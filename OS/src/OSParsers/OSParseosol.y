/** @file parseosol.y
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 * @version 1.1, 10/07/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

%{


#include "OSDataStructures.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include <iostream>
#include <sstream>
#include <stdio.h>


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData ) throw(ErrorClass);


%}


%pure-parser
%locations
%defines
%parse-param{OSOption *osoption}
%parse-param{OSoLParserData *parserData}
%lex-param {void* scanner}




%union {
	double dval;
	int ival;
	char* sval;
}

/* %name-prefix="osol"
this fails in Mac OS X
*/

%{

void osolerror(YYLTYPE* type, OSOption *osoption,  OSoLParserData *parserData, const char* errormsg ) ;
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);

#define scanner parserData->scanner
%}

%token <sval> ATTRIBUTETEXT
%token <sval> ELEMENTTEXT
%token <ival> INTEGER
%token <dval> DOUBLE
%token <sval> QUOTE


%token GREATERTHAN ENDOFELEMENT
%token OSOLSTART OSOLATTRIBUTETEXT OSOLEND


%token LOCATIONTYPEATT TRANSPORTTYPEATT NUMBEROFOTHEROPTIONSATT;
%token NUMBEROFJOBIDSATT NUMBEROFPATHSATT NUMBEROFPATHPAIRSATT;
%token FROMATT TOATT MAKECOPYATT SOLVERATT CATEGORYATT TYPEATT GROUPWEIGHTATT;
%token NUMBEROFPROCESSESATT NUMBEROFSOLVEROPTIONSATT NUMBEROFSOSATT;
%token NUMBEROFVARIABLESATT NUMBEROFOBJECTIVESATT NUMBEROFCONSTRAINTSATT;
%token NUMBEROFOTHERVARIABLEOPTIONSATT NUMBEROFOTHEROBJECTIVEOPTIONSATT;
%token NUMBEROFOTHERCONSTRAINTOPTIONSATT;
%token NUMBEROFVARATT NUMBEROFOBJATT NUMBEROFCONATT;
%token NAMEATT IDXATT SOSIDXATT VALUEATT UNITATT DESCRIPTIONATT;
%token LBVALUEATT UBVALUEATT LBDUALVALUEATT UBDUALVALUEATT;

%token GENERALSTART GENERALEND SYSTEMSTART SYSTEMEND SERVICESTART SERVICEEND;
%token JOBSTART JOBEND OPTIMIZATIONSTART OPTIMIZATIONEND;
%token SERVICEURISTART SERVICEURIEND SERVICENAMESTART SERVICENAMEEND;
%token INSTANCENAMESTART INSTANCENAMEEND INSTANCELOCATIONSTART INSTANCELOCATIONEND;
%token JOBIDSTART JOBIDEND SOLVERTOINVOKESTART SOLVERTOINVOKEEND;
%token LICENSESTART LICENSEEND USERNAMESTART USERNAMEEND PASSWORDSTART PASSWORDEND;
%token CONTACTSTART CONTACTEND OTHEROPTIONSSTART OTHEROPTIONSEND OTHERSTART OTHEREND;
%token MINDISKSPACESTART MINDISKSPACEEND MINMEMORYSIZESTART MINMEMORYSIZEEND MINCPUSPEEDSTART MINCPUSPEEDEND;
%token MINCPUNUMBERSTART MINCPUNUMBEREND SERVICETYPESTART SERVICETYPEEND;
%token MAXTIMESTART MAXTIMEEND SCHEDULEDSTARTTIMESTART SCHEDULEDSTARTTIMEEND;
%token DEPENDENCIESSTART DEPENDENCIESEND;
%token REQUIREDDIRECTORIESSTART REQUIREDDIRECTORIESEND REQUIREDFILESSTART REQUIREDFILESEND;
%token PATHSTART PATHEND PATHPAIRSTART PATHPAIREND;
%token DIRECTORIESTOMAKESTART DIRECTORIESTOMAKEEND FILESTOMAKESTART FILESTOMAKEEND;
%token DIRECTORIESTODELETESTART DIRECTORIESTODELETEEND FILESTODELETESTART FILESTODELETEEND;
%token  INPUTDIRECTORIESTOMOVESTART  INPUTDIRECTORIESTOMOVEEND  INPUTFILESTOMOVESTART  INPUTFILESTOMOVEEND;
%token OUTPUTDIRECTORIESTOMOVESTART OUTPUTDIRECTORIESTOMOVEEND OUTPUTFILESTOMOVESTART OUTPUTFILESTOMOVEEND;
%token PROCESSESTOKILLSTART PROCESSESTOKILLEND PROCESSSTART PROCESSEND;
%token VARIABLESSTART VARIABLESEND;
%token INITIALVARIABLEVALUESSTART INITIALVARIABLEVALUESEND VARSTART VAREND;
%token INITIALVARIABLEVALUESSTRINGSTART INITIALVARIABLEVALUESSTRINGEND;
%token INITIALBASISSTATUSSTART INITIALBASISSTATUSEND;
%token INTEGERVARIABLEBRANCHINGWEIGHTSSTART INTEGERVARIABLEBRANCHINGWEIGHTSEND
%token SOSVARIABLEBRANCHINGWEIGHTSSTART SOSVARIABLEBRANCHINGWEIGHTSEND
%token SOSSTART SOSEND

%token OBJECTIVESSTART OBJECTIVESEND;
%token INITIALOBJECTIVEVALUESSTART INITIALOBJECTIVEVALUESEND OBJSTART OBJEND;
%token INITIALOBJECTIVEBOUNDSSTART INITIALOBJECTIVEBOUNDSEND;
%token CONSTRAINTSSTART CONSTRAINTSEND;
%token INITIALCONSTRAINTVALUESSTART INITIALCONSTRAINTVALUESEND CONSTART CONEND;
%token INITIALDUALVALUESSTART INITIALDUALVALUESEND;
%token SOLVEROPTIONSSTART SOLVEROPTIONSEND SOLVEROPTIONSTART SOLVEROPTIONEND;

%token DUMMY

%%


osoldoc: osolstart GREATERTHAN osolcontent OSOLEND;
	| osolstart ENDOFELEMENT;

osolstart:	OSOLSTART
	| OSOLSTART OSOLATTRIBUTETEXT ;

osolcontent: osolgeneral osolsystem osolservice osoljob osoloptimization;

osolgeneral: | generalhead generalbody;

generalhead: GENERALSTART
{	if (parserData->osolgeneralPresent)
	{	osolerror( NULL, osoption, parserData, "only one <general> element allowed");
	}
	else
	{	parserData->osolgeneralPresent = true;
		osoption->general = new GeneralOption();
	}
};

generalbody:
	  GREATERTHAN generalcontent GENERALEND
	| ENDOFELEMENT;

generalcontent: | generalcontent generaloption;

generaloption: serviceURI | servicename | instancename | instancelocation | jobid
 | solvertoinvoke | license | username | password | contact | othergeneraloptions;


serviceURI: serviceURIhead serviceURIbody;

serviceURIhead: SERVICEURISTART
{	if (parserData->serviceURIPresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceURI> element allowed");
	}
	else
	{	parserData->serviceURIPresent = true;
	}
};

serviceURIbody: ENDOFELEMENT
	| GREATERTHAN SERVICEURIEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->serviceURI = $2;} SERVICEURIEND;


servicename: servicenamehead servicenamebody;

servicenamehead: SERVICENAMESTART
{	if (parserData->serviceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceName> element allowed");
	}
	else
	{	parserData->serviceNamePresent = true;
	}
};

servicenamebody: ENDOFELEMENT
	| GREATERTHAN SERVICENAMEEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->serviceName = $2;} SERVICENAMEEND;


instancename: instancenamehead instancenamebody;

instancenamehead: INSTANCENAMESTART
{	if (parserData->instanceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceName> element allowed");
	}
	else
	{	parserData->instanceNamePresent = true;
	}
};

instancenamebody: ENDOFELEMENT
	| GREATERTHAN INSTANCENAMEEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->instanceName = $2;} INSTANCENAMEEND;


instancelocation: instancelocationhead locationtypeatt instancelocationbody;

instancelocationhead: INSTANCELOCATIONSTART
{	if (parserData->instanceLocationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceLocation> element allowed");
	}
	else
	{	parserData->instanceLocationPresent = true;
		osoption->general->instanceLocation = new InstanceLocationOption();
		osoption->general->instanceLocation->locationType = "local";
	}
};

locationtypeatt: | LOCATIONTYPEATT ATTRIBUTETEXT 
{	if ( (strcmp($2, "local") == 0) || (strcmp($2, "http") == 0) || (strcmp($2, "ftp") == 0) )
		osoption->general->instanceLocation->locationType = $2;
	else
		osolerror( NULL, osoption, parserData, "Not a valid locationType");
} 
QUOTE;

instancelocationbody: ENDOFELEMENT
	|   GREATERTHAN instancelocationtext INSTANCELOCATIONEND;

instancelocationtext: | ELEMENTTEXT {osoption->general->instanceLocation->value = $1;};


jobid: jobidhead jobidbody;

jobidhead: JOBIDSTART
{	if (parserData->jobIDPresent)
	{	osolerror( NULL, osoption, parserData, "only one <jobID> element allowed");
	}
	else
	{	parserData->jobIDPresent = true;
	}
};

jobidbody: ENDOFELEMENT
	| GREATERTHAN JOBIDEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->jobID = $2;} JOBIDEND;


solvertoinvoke: solvertoinvokehead solvertoinvokebody;

solvertoinvokehead: SOLVERTOINVOKESTART
{	if (parserData->solverToInvokePresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverToInvoke> element allowed");
	}
	else
	{	parserData->solverToInvokePresent = true;
	}
};

solvertoinvokebody: ENDOFELEMENT
	| GREATERTHAN SOLVERTOINVOKEEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->solverToInvoke = $2;} SOLVERTOINVOKEEND;


license: licensehead licensebody;

licensehead: LICENSESTART
{	if (parserData->licensePresent)
	{	osolerror( NULL, osoption, parserData, "only one <license> element allowed");
	}
	else
	{	parserData->licensePresent = true;	
	}
};

licensebody: ENDOFELEMENT
	| GREATERTHAN LICENSEEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->license = $2;} LICENSEEND;


username: usernamehead usernamebody;

usernamehead: USERNAMESTART
{	if (parserData->usernamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <userName> element allowed");
	}
	else
	{	parserData->usernamePresent = true;
	}
};

usernamebody: ENDOFELEMENT
	| GREATERTHAN USERNAMEEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->userName = $2;} USERNAMEEND;


password: passwordhead passwordbody;

passwordhead: PASSWORDSTART
{	if (parserData->passwordPresent)
	{	osolerror( NULL, osoption, parserData, "only one <password> element allowed");
	}
	else
	{	parserData->passwordPresent = true;
	}
};

passwordbody: ENDOFELEMENT
	| GREATERTHAN PASSWORDEND
	| GREATERTHAN ELEMENTTEXT {osoption->general->password = $2;} PASSWORDEND;


contact: contacthead transporttypeatt contactbody;

contacthead: CONTACTSTART
{	if (parserData->contactPresent)
	{	osolerror( NULL, osoption, parserData, "only one <contact> element allowed");
	}
	else
	{	parserData->contactPresent = true;
		osoption->general->contact = new ContactOption();
		osoption->general->contact->transportType = "osp";
	}
};

transporttypeatt: | TRANSPORTTYPEATT ATTRIBUTETEXT 
{	if ( (strcmp($2,"osp") == 0) || (strcmp($2,"smtp") == 0) || (strcmp($2,"http")  == 0) || 
						  (strcmp($2,"ftp")  == 0) || (strcmp($2,"other") == 0) )
		osoption->general->contact->transportType = $2;
	else
		osolerror( NULL, osoption, parserData, "Not a valid transport type");
} 
QUOTE;

contactbody: ENDOFELEMENT
	|   GREATERTHAN contacttext CONTACTEND;

contacttext: | ELEMENTTEXT {osoption->general->contact->value = $1;};


othergeneraloptions: othergeneraloptionshead numberofothergeneraloptions GREATERTHAN othergeneraloptionsbody;

othergeneraloptionshead: OTHEROPTIONSSTART
{	if (parserData->otherGeneralOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherGeneralOptionsPresent = true;
		osoption->general->otherOptions = new OtherOptions();
	}
};

numberofothergeneraloptions: NUMBEROFOTHEROPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->general->otherOptions->numberOfOtherOptions = $3;
	osoption->general->otherOptions->other = new OtherOption*[$3];
	for (int i=0; i < $3; i++) osoption->general->otherOptions->other[i] = new OtherOption();
};

othergeneraloptionsbody: othergeneraloptionslist OTHEROPTIONSEND
{	if (parserData->numberOfOtherGeneralOptions != osoption->general->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <general> element");
};

othergeneraloptionslist: | othergeneraloptionslist othergeneraloption;

othergeneraloption: OTHERSTART
	{	if (parserData->numberOfOtherGeneralOptions >= osoption->general->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <general> element");
		};
	}
    othergeneralattributes othergeneraloptionend
{	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherGeneralOptions++;
};


othergeneralattributes: | othergeneralattributes othergeneralattribute;

othergeneralattribute: generaloptionnameatt | generaloptionvalueatt | generaloptiondescriptionatt;

generaloptionnameatt: NAMEATT ATTRIBUTETEXT
{	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->name = $2;
	}
}
QUOTE;

generaloptionvalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->value = $2;
	}
}
QUOTE;

generaloptiondescriptionatt: DESCRIPTIONATT ATTRIBUTETEXT
{	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->description = $2;
	}
}
QUOTE;

othergeneraloptionend: ENDOFELEMENT | GREATERTHAN OTHEREND;


osolsystem: | systemhead systembody;

systemhead: SYSTEMSTART
{	if (parserData->osolsystemPresent)
	{	osolerror( NULL, osoption, parserData, "only one <system> element allowed");
	}
	else
	{	parserData->osolsystemPresent = true;
		osoption->system = new SystemOption();
	}
};

systembody:
	  GREATERTHAN systemcontent SYSTEMEND
	| ENDOFELEMENT;

systemcontent: | systemcontent systemoption;

systemoption: mindiskspace | minmemorysize | mincpuspeed | mincpunumber | othersystemoptions;

mindiskspace: mindiskspacehead mindiskspaceunit mindiskspacebody;

mindiskspacehead: MINDISKSPACESTART
{	if (parserData->minDiskSpacePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minDiskSpace> element allowed");
	}
	else
	{	parserData->minDiskSpacePresent = true;
		osoption->system->minDiskSpace = new MinDiskSpace();
		osoption->system->minDiskSpace->unit = "byte";
	}
};

mindiskspaceunit: | UNITATT ATTRIBUTETEXT 
{	if ( (strcmp($2,"byte") == 0) || (strcmp($2,"kilobyte") == 0) || (strcmp($2,"megabyte") == 0) || 
						   (strcmp($2,"terabyte") == 0) || (strcmp($2,"petabyte") == 0) )
		osoption->system->minDiskSpace->unit = $2;
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
} 
QUOTE;

mindiskspacebody: ENDOFELEMENT
	| GREATERTHAN MINDISKSPACEEND
        | GREATERTHAN DOUBLE MINDISKSPACEEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = $2;
}
        | GREATERTHAN INTEGER MINDISKSPACEEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = $2;
};

 
minmemorysize: minmemorysizehead minmemoryunit minmemorysizebody;

minmemorysizehead: MINMEMORYSIZESTART
{	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData->minMemorySizePresent = true;
		osoption->system->minMemorySize = new MinMemorySize();
		osoption->system->minMemorySize->unit = "byte";
	}
};

minmemoryunit: | UNITATT ATTRIBUTETEXT 
{	if ( (strcmp($2,"byte") == 0) || (strcmp($2,"kilobyte") == 0) || (strcmp($2,"megabyte") == 0) || 
						   (strcmp($2,"terabyte") == 0) || (strcmp($2,"petabyte") == 0) )
		osoption->system->minMemorySize->unit = $2;
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
} 
QUOTE;

minmemorysizebody: ENDOFELEMENT
	| GREATERTHAN MINMEMORYSIZEEND
        | GREATERTHAN DOUBLE MINMEMORYSIZEEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = $2;
}
        | GREATERTHAN INTEGER MINMEMORYSIZEEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = $2;
};



mincpuspeed: mincpuspeedhead mincpuspeedunit mincpuspeedbody;

mincpuspeedhead: MINCPUSPEEDSTART
{	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData->minCPUSpeedPresent = true;
		osoption->system->minCPUSpeed = new MinCPUSpeed();
		osoption->system->minCPUSpeed->unit = "hertz";
	}
};

mincpuspeedunit: | UNITATT ATTRIBUTETEXT 
{	if ( (strcmp($2,    "hertz") == 0) || (strcmp($2,"kilohertz") == 0) || (strcmp($2,"megahertz") == 0) || 
	     (strcmp($2,"gigahertz") == 0) || (strcmp($2,"terahertz") == 0) || (strcmp($2,"petahertz") == 0) ||
	     (strcmp($2,    "flops") == 0) || (strcmp($2,"kiloflops") == 0) || (strcmp($2,"megaflops") == 0) || 
	     (strcmp($2,"gigaflops") == 0) || (strcmp($2,"teraflops") == 0) || (strcmp($2,"petahertz") == 0) ) 
		osoption->system->minCPUSpeed->unit = $2;
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
} 
QUOTE;

mincpuspeedbody: ENDOFELEMENT
	| GREATERTHAN MINCPUSPEEDEND
        | GREATERTHAN DOUBLE MINCPUSPEEDEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = $2;
}
        | GREATERTHAN INTEGER MINCPUSPEEDEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = $2;
};



mincpunumber: mincpunumberhead mincpunumberbody;

mincpunumberhead: MINCPUNUMBERSTART
{	if (parserData->minCPUNumberPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUNumber> element allowed");
	}
	else
	{	parserData->minCPUNumberPresent = true;
	}
};

mincpunumberbody: ENDOFELEMENT
	| GREATERTHAN MINCPUNUMBEREND
	| GREATERTHAN INTEGER 
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "minCPUNumber cannot be negative");
	osoption->system->minCPUNumber = $2;
} 
MINCPUNUMBEREND;


othersystemoptions: othersystemoptionshead numberofothersystemoptions GREATERTHAN othersystemoptionsbody;

othersystemoptionshead: OTHEROPTIONSSTART
{	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();
	}
};

numberofothersystemoptions: NUMBEROFOTHEROPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->system->otherOptions->numberOfOtherOptions = $3;
	osoption->system->otherOptions->other = new OtherOption*[$3];
	for (int i=0; i < $3; i++) osoption->system->otherOptions->other[i] = new OtherOption();
};

othersystemoptionsbody: othersystemoptionslist OTHEROPTIONSEND
{	if (parserData->numberOfOtherSystemOptions != osoption->system->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <system> element");
};

othersystemoptionslist: | othersystemoptionslist othersystemoption;

othersystemoption: OTHERSTART
	{	if (parserData->numberOfOtherSystemOptions >= osoption->system->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <system> element");
		};
	}
    othersystemattributes othersystemoptionend
{	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
};

othersystemattributes: | othersystemattributes othersystemattribute;

othersystemattribute: systemoptionnameatt | systemoptionvalueatt | systemoptiondescriptionatt;

systemoptionnameatt: NAMEATT ATTRIBUTETEXT
{	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = $2;
	}
}
QUOTE;

systemoptionvalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = $2;
	}
}
QUOTE;


systemoptiondescriptionatt: DESCRIPTIONATT ATTRIBUTETEXT
{	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = $2;
	}
}
QUOTE;

othersystemoptionend: ENDOFELEMENT | GREATERTHAN OTHEREND;


osolservice: | servicehead servicebody;

servicehead: SERVICESTART
{	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;
		osoption->service = new ServiceOption();
	}
};

servicebody:
	  GREATERTHAN servicecontent SERVICEEND
	| ENDOFELEMENT;

servicecontent: | servicecontent serviceoption;

serviceoption: servicetype | otherserviceoptions;

servicetype: servicetypehead servicetypebody;

servicetypehead: SERVICETYPESTART
{	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;
		osoption->service->type = "solver";
	}
};

servicetypebody: ENDOFELEMENT
	| GREATERTHAN SERVICETYPEEND
	| GREATERTHAN ELEMENTTEXT 
{	if ( (strcmp($2,"solver") == 0) || (strcmp($2,"analyzer")   == 0) || (strcmp($2,"scheduler") == 0) ||
						     (strcmp($2,"simulation") == 0) || (strcmp($2,"registry")  == 0) ||
						     (strcmp($2,"modeler")    == 0) || (strcmp($2,"agent")     == 0) ) 
		osoption->service->type = $2;
	else
		osolerror( NULL, osoption, parserData, "Not a valid service type");
} 
SERVICETYPEEND;

otherserviceoptions: otherserviceoptionshead numberofotherserviceoptions GREATERTHAN otherserviceoptionsbody;

otherserviceoptionshead: OTHEROPTIONSSTART
{	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();
	}
};

numberofotherserviceoptions: NUMBEROFOTHEROPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->service->otherOptions->numberOfOtherOptions = $3;
	osoption->service->otherOptions->other = new OtherOption*[$3];
	for (int i=0; i < $3; i++) osoption->service->otherOptions->other[i] = new OtherOption();
};

otherserviceoptionsbody: otherserviceoptionslist OTHEROPTIONSEND
{	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element");
};

otherserviceoptionslist: | otherserviceoptionslist otherserviceoption;

otherserviceoption: OTHERSTART
	{	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	}
otherserviceattributes otherserviceoptionsend
{	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
};

otherserviceattributes: | otherserviceattributes otherserviceattribute;

otherserviceattribute: serviceoptionnameatt | serviceoptionvalueatt | serviceoptiondescriptionatt;

serviceoptionnameatt: NAMEATT ATTRIBUTETEXT
{	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = $2;
	}
}
QUOTE;

serviceoptionvalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = $2;
	}
}
QUOTE;

serviceoptiondescriptionatt: DESCRIPTIONATT ATTRIBUTETEXT
{	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = $2;
	}
}
QUOTE;

otherserviceoptionsend: ENDOFELEMENT | GREATERTHAN OTHEREND;


osoljob: | jobhead jobbody;

jobhead: JOBSTART
{	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
};

jobbody: GREATERTHAN jobcontent JOBEND
	|  ENDOFELEMENT;

jobcontent: | jobcontent joboption;

joboption: maxtime | scheduledstarttime | dependencies | requireddirectories | requiredfiles
| directoriestomake | filestomake | inputdirectoriestomove | inputfilestomove | outputdirectoriestomove
| outputfilestomove | filestodelete | directoriestodelete | processestokill | otherjoboptions;


maxtime: maxtimehead maxtimeunit maxtimebody;

maxtimehead: MAXTIMESTART
{	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData->maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
		osoption->job->maxTime->unit = "second"; 
	}
};

maxtimeunit: | UNITATT ATTRIBUTETEXT 
{	if ( (strcmp($2,"second") == 0) || (strcmp($2,"minute") == 0) || (strcmp($2,"hour") == 0) ||
						     (strcmp($2,"day")    == 0) || (strcmp($2,"week") == 0) ||
						     (strcmp($2,"month")  == 0) || (strcmp($2,"year") == 0) ) 
                osoption->job->maxTime->unit = $2;
	else
		osolerror( NULL, osoption, parserData, "Not a valid time unit");
} 
QUOTE;

maxtimebody: ENDOFELEMENT
	| GREATERTHAN MAXTIMEEND
        | GREATERTHAN DOUBLE MAXTIMEEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = $2;
}
        | GREATERTHAN INTEGER MAXTIMEEND
{	if ($2 < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = $2;
};


scheduledstarttime: starttimehead starttimebody;

starttimehead: SCHEDULEDSTARTTIMESTART
{	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;
		osoption->job->scheduledStartTime = "1970-01-01T00:00:00-00:00";
	}
};

starttimebody: ENDOFELEMENT
	| GREATERTHAN SCHEDULEDSTARTTIMEEND
	| GREATERTHAN ELEMENTTEXT {osoption->job->scheduledStartTime = $2;} SCHEDULEDSTARTTIMEEND;

dependencies: dependencieshead numberofjobidsatt GREATERTHAN dependencieslist DEPENDENCIESEND;

dependencieshead: DEPENDENCIESSTART
{	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
};

numberofjobidsatt: NUMBEROFJOBIDSATT QUOTE INTEGER QUOTE
{	if ($3 < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->dependencies->numberOfJobIDs = $3;
	osoption->job->dependencies->jobID = new std::string[$3];
};

dependencieslist: | dependencieslist dependencyjobid;

dependencyjobid: JOBIDSTART GREATERTHAN ELEMENTTEXT
{
	if (parserData->numberOfDependencies >= osoption->job->dependencies->numberOfJobIDs)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <dependencies> element");
	}
	else
	{	osoption->job->dependencies->jobID[parserData->numberOfDependencies] = $3;
		parserData->numberOfDependencies++;
	};
}
JOBIDEND;


requireddirectories: requireddirectorieshead numberofreqdirpathsatt GREATERTHAN reqdirpathlist
   REQUIREDDIRECTORIESEND;

requireddirectorieshead: REQUIREDDIRECTORIESSTART
{	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
};

numberofreqdirpathsatt: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{	if ($3 < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredDirectories->numberOfPaths = $3;
	osoption->job->requiredDirectories->path = new std::string[$3];
};

reqdirpathlist: | reqdirpathlist reqdirpath;

reqdirpath: PATHSTART GREATERTHAN ELEMENTTEXT {
	if (parserData->numberOfRequiredDirectories >= osoption->job->requiredDirectories->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredDirectories> element");
	}
	else
	{	osoption->job->requiredDirectories->path[parserData->numberOfRequiredDirectories] = $3;
		parserData->numberOfRequiredDirectories++;
	};
}
PATHEND;


requiredfiles: requiredfileshead numberofreqfilespathsatt GREATERTHAN reqfilespathlist
   REQUIREDFILESEND;

requiredfileshead: REQUIREDFILESSTART
{	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
};

numberofreqfilespathsatt: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{	if ($3 < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredFiles->numberOfPaths = $3;
	osoption->job->requiredFiles->path = new std::string[$3];
};

reqfilespathlist: | reqfilespathlist reqfilepath;

reqfilepath: PATHSTART GREATERTHAN ELEMENTTEXT {
	if (parserData->numberOfRequiredFiles >= osoption->job->requiredFiles->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredFiles> element");
	}
	else
	{	osoption->job->requiredFiles->path[parserData->numberOfRequiredFiles] = $3;
		parserData->numberOfRequiredFiles++;
	};
}
PATHEND;


directoriestomake: directoriestomakehead numberofdirtomakepathsatt GREATERTHAN dirtomakepathlist
   DIRECTORIESTOMAKEEND;

directoriestomakehead: DIRECTORIESTOMAKESTART
{	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
};
numberofdirtomakepathsatt: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{	if ($3 < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToMake->numberOfPaths = $3;
	osoption->job->directoriesToMake->path = new std::string[$3];
};

dirtomakepathlist: | dirtomakepathlist dirtomakepath;

dirtomakepath: PATHSTART GREATERTHAN ELEMENTTEXT
{	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = $3;
		parserData->numberOfDirectoriesToMake++;
	};
}
PATHEND;


filestomake: filestomakehead numberoffilestomakepathsatt GREATERTHAN filestomakepathlist
   FILESTOMAKEEND;

filestomakehead: FILESTOMAKESTART
{	if (parserData->filesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToMake> element allowed");
	}
	else
	{	parserData->filesToMakePresent = true;
		osoption->job->filesToMake = new DirectoriesAndFiles();
	}
};

numberoffilestomakepathsatt: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of paths cannot be negative");
	osoption->job->filesToMake->numberOfPaths = $3;
	osoption->job->filesToMake->path = new std::string[$3];
};

filestomakepathlist: | filestomakepathlist filestomakepath;

filestomakepath: PATHSTART GREATERTHAN ELEMENTTEXT
{	if (parserData->numberOfFilesToMake >= osoption->job->filesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToMake> element");
	}
	else
	{	osoption->job->filesToMake->path[parserData->numberOfFilesToMake] = $3;
		parserData->numberOfFilesToMake++;
	};
}
PATHEND;


inputdirectoriestomove: inputdirectoriestomovehead numberofindirtomovepathpairsatt
   GREATERTHAN indirtomovepathpairlist INPUTDIRECTORIESTOMOVEEND;

inputdirectoriestomovehead: INPUTDIRECTORIESTOMOVESTART
{	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
};

numberofindirtomovepathpairsatt: NUMBEROFPATHPAIRSATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = $3;
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[$3];
	for (int i = 0; i < $3; i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
};

indirtomovepathpairlist: | indirtomovepathpairlist indirtomovepathpair;

indirtomovepathpair: indirtomovepathpairhead indirtomovepathpairattlist indirtomovepathpairend
{	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputDirectoriesToMove++;
};

indirtomovepathpairhead: PATHPAIRSTART
{	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
};

indirtomovepathpairattlist: | indirtomovepathpairattlist indirtomovepathpairatt;

indirtomovepathpairatt: indirtomovefromatt | indirtomovetoatt | indirtomovemakecopyatt;

indirtomovefromatt: FROMATT ATTRIBUTETEXT
{	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = $2;
	}
}
QUOTE;

indirtomovetoatt: TOATT ATTRIBUTETEXT
{	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = $2;
	}
}
QUOTE;

indirtomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT
{	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ($2 == "true")
			osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->makeCopy = true;
	}
}
QUOTE;

indirtomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


inputfilestomove: inputfilestomovehead numberofinfilestomovepathpairsatt
   GREATERTHAN infilestomovepathpairlist INPUTFILESTOMOVEEND;

inputfilestomovehead: INPUTFILESTOMOVESTART
{	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
};

numberofinfilestomovepathpairsatt: NUMBEROFPATHPAIRSATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = $3;
	osoption->job->inputFilesToMove->pathPair = new PathPair*[$3];
	for (int i = 0; i < $3; i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
};

infilestomovepathpairlist: | infilestomovepathpairlist infilestomovepathpair;

infilestomovepathpair: infilestomovepathpairhead infilestomovepathpairattlist infilestomovepathpairend
{	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputFilesToMove++;
};

infilestomovepathpairhead: PATHPAIRSTART
{	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
}

infilestomovepathpairattlist: | infilestomovepathpairattlist infilestomovepathpairatt;

infilestomovepathpairatt: infilestomovefromatt | infilestomovetoatt | infilestomovemakecopyatt;

infilestomovefromatt: FROMATT ATTRIBUTETEXT
{	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = $2;
	}
}
QUOTE;

infilestomovetoatt: TOATT ATTRIBUTETEXT
{	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = $2;
	}
}
QUOTE;

infilestomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT
{	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ($2 == "true")
			osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->makeCopy = true;
	}
}
QUOTE;

infilestomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


outputdirectoriestomove: outputdirectoriestomovehead numberofoutdirtomovepathpairsatt
   GREATERTHAN outdirtomovepathpairlist OUTPUTDIRECTORIESTOMOVEEND;

outputdirectoriestomovehead: OUTPUTDIRECTORIESTOMOVESTART
{	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
};

numberofoutdirtomovepathpairsatt: NUMBEROFPATHPAIRSATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = $3;
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[$3];
	for (int i = 0; i < $3; i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
};

outdirtomovepathpairlist: | outdirtomovepathpairlist outdirtomovepathpair;

outdirtomovepathpair: outdirtomovepathpairhead outdirtomovepathpairattlist outdirtomovepathpairend
{	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputDirectoriesToMove++;
};

outdirtomovepathpairhead: PATHPAIRSTART
{	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
}

outdirtomovepathpairattlist: | outdirtomovepathpairattlist outdirtomovepathpairatt;

outdirtomovepathpairatt: outdirtomovefromatt | outdirtomovetoatt | outdirtomovemakecopyatt;

outdirtomovefromatt: FROMATT ATTRIBUTETEXT
{	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = $2;
	}
}
QUOTE;

outdirtomovetoatt: TOATT ATTRIBUTETEXT
{	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = $2;
	}
}
QUOTE;

outdirtomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT
{	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ($2 == "true")
			osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->makeCopy = true;
	}
}
QUOTE;

outdirtomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


outputfilestomove: outputfilestomovehead numberofoutfilestomovepathpairsatt
   GREATERTHAN outfilestomovepathpairlist OUTPUTFILESTOMOVEEND;

outputfilestomovehead: OUTPUTFILESTOMOVESTART
{	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
};

numberofoutfilestomovepathpairsatt: NUMBEROFPATHPAIRSATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = $3;
	osoption->job->outputFilesToMove->pathPair = new PathPair*[$3];
	for (int i = 0; i < $3; i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();};

outfilestomovepathpairlist: | outfilestomovepathpairlist outfilestomovepathpair;

outfilestomovepathpair: outfilestomovepathpairhead outfilestomovepathpairattlist outfilestomovepathpairend
{	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputFilesToMove++;
};

outfilestomovepathpairhead: PATHPAIRSTART
{	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
}

outfilestomovepathpairattlist: | outfilestomovepathpairattlist outfilestomovepathpairatt;

outfilestomovepathpairatt: outfilestomovefromatt | outfilestomovetoatt | outfilestomovemakecopyatt;

outfilestomovefromatt: FROMATT ATTRIBUTETEXT
{	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = $2;
	}
}
QUOTE;

outfilestomovetoatt: TOATT ATTRIBUTETEXT
{	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = $2;
	}
}
QUOTE;

outfilestomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT
{	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ($2 == "true")
			osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->makeCopy = true;
	}
}
QUOTE;

outfilestomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


filestodelete: filestodeletehead numberoffilestodeletepathsatt GREATERTHAN filestodeletepathlist
   FILESTODELETEEND;

filestodeletehead: FILESTODELETESTART
{	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
};

numberoffilestodeletepathsatt: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{	if ($3 < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->filesToDelete->numberOfPaths = $3;
	osoption->job->filesToDelete->path = new std::string[$3];
};

filestodeletepathlist: | filestodeletepathlist filestodeletepath;

filestodeletepath: PATHSTART GREATERTHAN ELEMENTTEXT
{	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = $3;
		parserData->numberOfFilesToDelete++;
	};
}
PATHEND;


directoriestodelete: directoriestodeletehead numberofdirtodeletepathsatt GREATERTHAN dirtodeletepathlist
   DIRECTORIESTODELETEEND;

directoriestodeletehead: DIRECTORIESTODELETESTART
{	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
};

numberofdirtodeletepathsatt: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{	if ($3 < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToDelete->numberOfPaths = $3;
	osoption->job->directoriesToDelete->path = new std::string[$3];
};

dirtodeletepathlist: | dirtodeletepathlist dirtodeletepath;

dirtodeletepath: PATHSTART GREATERTHAN ELEMENTTEXT
{	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = $3;
		parserData->numberOfDirectoriesToDelete++;
	};
}
PATHEND;


processestokill: processestokillhead numberofprocesstokillatt GREATERTHAN processestokilllist
   PROCESSESTOKILLEND;


processestokillhead: PROCESSESTOKILLSTART
{	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
};

numberofprocesstokillatt: NUMBEROFPROCESSESATT QUOTE INTEGER QUOTE
{	if ($3 < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->processesToKill->numberOfProcesses = $3;
	osoption->job->processesToKill->process = new std::string[$3];
};

processestokilllist: | processestokilllist processtokill;

processtokill: PROCESSSTART GREATERTHAN ELEMENTTEXT
{	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = $3;
		parserData->numberOfProcessesToKill++;
	};
}
PROCESSEND;


otherjoboptions: otherjoboptionshead numberofotherjoboptions GREATERTHAN otherjoboptionsbody;

otherjoboptionshead: OTHEROPTIONSSTART
{	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
};

numberofotherjoboptions: NUMBEROFOTHEROPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->job->otherOptions->numberOfOtherOptions = $3;
	osoption->job->otherOptions->other = new OtherOption*[$3];
	for (int i=0; i < $3; i++) osoption->job->otherOptions->other[i] = new OtherOption();
};

otherjoboptionsbody: otherjoboptionslist OTHEROPTIONSEND
{	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
};

otherjoboptionslist: | otherjoboptionslist otherjoboption;

otherjoboption: OTHERSTART
	{	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	}
otherjobattributes otherjoboptionsend
{	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
};

otherjobattributes: | otherjobattributes otherjobattribute;

otherjobattribute: joboptionnameatt | joboptionvalueatt | joboptiondescriptionatt;

joboptionnameatt: NAMEATT ATTRIBUTETEXT
{	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = $2;
	}
}
QUOTE;

joboptionvalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = $2;
	}
}
QUOTE;

joboptiondescriptionatt: DESCRIPTIONATT ATTRIBUTETEXT
{	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = $2;
	}
}
QUOTE;

otherjoboptionsend: ENDOFELEMENT | GREATERTHAN OTHEREND;


osoloptimization: | optimizationhead optimizationattlist optimizationbody;

optimizationhead: OPTIMIZATIONSTART
{	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
};

optimizationattlist: | optimizationattlist optimizationatt;

optimizationatt: optimizationnvar | optimizationncon | optimizationnobj;

optimizationnvar: NUMBEROFVARIABLESATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of variables cannot be negative");
	osoption->optimization->numberOfVariables = $3;
};

optimizationncon: NUMBEROFCONSTRAINTSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of constraints cannot be negative");
	osoption->optimization->numberOfConstraints = $3;
};

optimizationnobj: NUMBEROFOBJECTIVESATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror( NULL, osoption, parserData, "Number of objectives cannot be negative");
	osoption->optimization->numberOfObjectives = $3;
};

optimizationbody: GREATERTHAN optimizationcontent OPTIMIZATIONEND | ENDOFELEMENT;

optimizationcontent: variables objectives constraints solveroptions;

variables: | variablesstart numberofothervariablesatt restofvariables;

variablesstart: VARIABLESSTART
{	osoption->optimization->variables = new VariableOption();
};

numberofothervariablesatt: | NUMBEROFOTHERVARIABLEOPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = $3;
	osoption->optimization->variables->other = new OtherVariableOption*[$3];
	for (int i= 0; i < $3; i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
};

restofvariables: GREATERTHAN initialvariablevalues initialvariablevaluesstring initialbasisstatus 
   integervariablebranchingweights sosvariablebranchingweights othervariableoptionlist VARIABLESEND
   | ENDOFELEMENT;

initialvariablevalues: | INITIALVARIABLEVALUESSTART numberofvar GREATERTHAN varlist INITIALVARIABLEVALUESEND;

numberofvar: NUMBEROFVARATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = $3;
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
};

varlist: | varlist initvarvalue;

initvarvalue: varstart initvarvalueattlist initvarvalueend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
};

varstart: VARSTART
{	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
};

initvarvalueattlist: | initvarvalueattlist initvarvalueatt;

initvarvalueatt: initvarvalueidxatt | initvarvaluevalueatt;

initvarvalueidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ($3 >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = $3;
};

initvarvaluevalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = os_strtod($2, NULL);
}
QUOTE;

initvarvalueend: GREATERTHAN VAREND | ENDOFELEMENT;


initialvariablevaluesstring: | INITIALVARIABLEVALUESSTRINGSTART numberofvarstr GREATERTHAN
    varstrlist INITIALVARIABLEVALUESSTRINGEND;

numberofvarstr: NUMBEROFVARATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = $3;
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
};

varstrlist: | varstrlist initvarstrvalue;

initvarstrvalue: varstrstart initvarstrvalueattlist initvarstrvalueend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
};

varstrstart: VARSTART
{	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
};

initvarstrvalueattlist: | initvarstrvalueattlist initvarstrvalueatt;

initvarstrvalueatt: initvarstrvalueidxatt | initvarstrvaluevalueatt;

initvarstrvalueidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ($3 >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->idx = $3;
};

initvarstrvaluevalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable string value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = $2;
}
QUOTE;

initvarstrvalueend: GREATERTHAN VAREND | ENDOFELEMENT;


initialbasisstatus: | INITIALBASISSTATUSSTART numberofbasvar GREATERTHAN
    basvarlist INITIALBASISSTATUSEND;

numberofbasvar: NUMBEROFVARATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	osoption->optimization->variables->initialBasisStatus->numberOfVar = $3;
	osoption->optimization->variables->initialBasisStatus->var = new InitBasStatus*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->variables->initialBasisStatus->var[i] = new InitBasStatus();
};

basvarlist: | basvarlist initbasvalue;

initbasvalue: basvarstart initbasvarvalueattlist initbasvarvalueend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfBasVar++;
};

basvarstart: VARSTART
{	if (parserData->numberOfBasVar >= osoption->optimization->variables->initialBasisStatus->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial basis variables");
};

initbasvarvalueattlist: | initbasvarvalueattlist initbasvarvalueatt;

initbasvarvalueatt: initbasvarvalueidxatt | initbasvarvaluevalueatt;

initbasvarvalueidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ($3 >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->idx = $3;
};

initbasvarvaluevalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->value = $2;
}
QUOTE;

initbasvarvalueend: GREATERTHAN VAREND | ENDOFELEMENT;


integervariablebranchingweights:  | INTEGERVARIABLEBRANCHINGWEIGHTSSTART numberofintegerweights
   GREATERTHAN intweightlist INTEGERVARIABLEBRANCHINGWEIGHTSEND;

numberofintegerweights: NUMBEROFVARATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar = $3;
	osoption->optimization->variables->integerVariableBranchingWeights->var = new BranchingWeight*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->variables->integerVariableBranchingWeights->var[i] = new BranchingWeight();
};

intweightlist: | intweightlist intweight;

intweight: intweightstart intweightattlist intweightend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfIntWt++;
};

intweightstart: VARSTART 
{	if (parserData->numberOfIntWt >= osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many integer branching weights");
};

intweightattlist: | intweightattlist intweightatt;

intweightatt: intweightidxatt | intweightvalueatt;

intweightidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ($3 >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->idx = $3;
};

intweightvalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one branching weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = os_strtod($2, NULL);
}
QUOTE;
                   
intweightend: GREATERTHAN  VAREND | ENDOFELEMENT;
    

sosvariablebranchingweights: | SOSVARIABLEBRANCHINGWEIGHTSSTART numberofsosweightgroups
   GREATERTHAN sosweightgrouplist SOSVARIABLEBRANCHINGWEIGHTSEND;

numberofsosweightgroups: NUMBEROFSOSATT QUOTE INTEGER QUOTE   
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <sos> elements must be positive");
	osoption->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS = $3;
	osoption->optimization->variables->sosVariableBranchingWeights->sos = new SOSWeights*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[i] = new SOSWeights();
};


sosweightgrouplist: | sosweightgrouplist sosweightgroup;

sosweightgroup: sosweightgroupstart sosweightgroupattlist sosweightgroupcontent
{	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "SOS index required");
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "numberOfVar required");
	parserData->sosIdxAttributePresent = false;
	parserData->grpWgtAttributePresent = false;
	parserData->nOfVarAttributePresent = false;
	parserData->numberOfSOS++;
};


sosweightgroupstart: SOSSTART
{	if (parserData->numberOfSOS >= osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
		osolerror(NULL, osoption, parserData, "too many SOS branching weights");
	parserData->numberOfSOSVar = 0;
};

sosweightgroupattlist: | sosweightgroupattlist sosweightgroupatt; 

sosweightgroupatt: sosweightgroupidxatt | sosweightgroupnvaratt	| sosweightgroupweightatt;

sosweightgroupidxatt: SOSIDXATT QUOTE INTEGER QUOTE
{	if (parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one SOS index allowed");
	parserData->sosIdxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "SOS index must be nonnegative");
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx = $3;
};
 
sosweightgroupweightatt: 
	  GROUPWEIGHTATT QUOTE DOUBLE QUOTE
{	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = $3;
}

	| GROUPWEIGHTATT QUOTE INTEGER QUOTE
{	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = $3;
};

sosweightgroupnvaratt: NUMBEROFVARATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
//	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS] = new SOSWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar = $3;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var = new BranchingWeight*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[i] = new BranchingWeight();
};

sosweightgroupcontent:
      GREATERTHAN sosweightgroupvars SOSEND
    | ENDOFELEMENT;

sosweightgroupvars: | sosweightgroupvars sosweightvar;

sosweightvar: sosweightvarstart sosweightvarattlist sosweightvarend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfSOSVar++;
};

sosweightvarstart: VARSTART 
{	if (parserData->numberOfSOSVar >= osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many variable branching weights");
};

sosweightvarattlist: | sosweightvarattlist sosweightvaratt;

sosweightvaratt: sosweightvaridxatt | sosweightvarvalueatt;

sosweightvaridxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ($3 >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->idx = $3;
}; 

sosweightvarvalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = os_strtod($2, NULL);
}
QUOTE;
	
sosweightvarend: GREATERTHAN VAREND | ENDOFELEMENT;


othervariableoptionlist: | othervariableoptionlist othervariableoption;

othervariableoption: othervariableoptionstart othervariableoptionsattlist restofothervariableoption;

othervariableoptionstart: OTHERSTART
{	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
};

othervariableoptionsattlist: | othervariableoptionsattlist othervariableoptionsatt;

othervariableoptionsatt:
     othervariableoptionnumberofvar
   | othervariableoptionname
   | othervariableoptionvalue
   | othervariableoptionsolver
   | othervariableoptioncategory
   | othervariableoptiontype
   | othervariableoptiondescription;

othervariableoptionnumberofvar: NUMBEROFVARATT QUOTE INTEGER QUOTE
{ 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfVar attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfVar = 0;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options must be nonnegative");
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar = $3;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var = new OtherVarOption*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[i] = new OtherVarOption();	
};

othervariableoptionname: NAMEATT ATTRIBUTETEXT
{	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = $2;
}
QUOTE;

othervariableoptionvalue: VALUEATT ATTRIBUTETEXT
{	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = $2;
}
QUOTE;

othervariableoptionsolver: SOLVERATT ATTRIBUTETEXT
{	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = $2;
}
QUOTE;

othervariableoptioncategory: CATEGORYATT ATTRIBUTETEXT
{	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = $2;
}
QUOTE;

othervariableoptiontype: TYPEATT ATTRIBUTETEXT
{	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = $2;
}
QUOTE;

othervariableoptiondescription: DESCRIPTIONATT ATTRIBUTETEXT
{	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = $2;
}
QUOTE;


restofothervariableoption: GREATERTHAN othervariableoptionsvarlist OTHEREND
{ 	if (parserData->numberOfVar < osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "not enough <var> entries in <other> variable element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherVariableOptions++;
};

othervariableoptionsvarlist: | othervariableoptionsvarlist othervariableoptionsvar;

othervariableoptionsvar: othervariableoptionsvarstart othervaroptionattlist othervaroptionend
{	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
};

othervariableoptionsvarstart: VARSTART
{	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
};

othervaroptionattlist: | othervaroptionattlist othervaroptionatt;

othervaroptionatt:
     othervaroptionidx
   | othervaroptionvalue
   | othervaroptionlbvalue
   | othervaroptionubvalue;

othervaroptionidx: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ($3 >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->idx = $3;
};

othervaroptionvalue: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = $2;
}
QUOTE;

othervaroptionlbvalue: LBVALUEATT ATTRIBUTETEXT
{	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = $2;
}
QUOTE;

othervaroptionubvalue: UBVALUEATT ATTRIBUTETEXT
{	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = $2;
}
QUOTE;

othervaroptionend: GREATERTHAN VAREND | ENDOFELEMENT;



objectives: | objectivesstart numberofotherobjectivesatt restofobjectives;

objectivesstart: OBJECTIVESSTART
{	osoption->optimization->objectives = new ObjectiveOption();
};

numberofotherobjectivesatt: | NUMBEROFOTHEROBJECTIVEOPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
	osoption->optimization->objectives->numberOfOtherObjectiveOptions = $3;
	osoption->optimization->objectives->other = new OtherObjectiveOption*[$3];
	for (int i= 0; i < $3; i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
};

restofobjectives: GREATERTHAN initialobjectivevalues initialobjectivebounds otherobjectiveoptionlist OBJECTIVESEND
   | ENDOFELEMENT;

initialobjectivevalues: | INITIALOBJECTIVEVALUESSTART numberofobjval GREATERTHAN
    objvaluelist INITIALOBJECTIVEVALUESEND;

numberofobjval: NUMBEROFOBJATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = $3;
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
};

objvaluelist: | objvaluelist initobjvalue;

initobjvalue: objvaluestart initobjvalueattlist initobjvalueend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
};

objvaluestart: OBJSTART
{	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
};

initobjvalueattlist: | initobjvalueattlist initobjvalueatt;

initobjvalueatt: initobjvalueidxatt | initobjvaluevalueatt;

initobjvalueidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ($3 >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-$3 > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->idx = $3;
};


initobjvaluevalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = os_strtod($2, NULL);
}
QUOTE;

initobjvalueend: GREATERTHAN OBJEND | ENDOFELEMENT;


initialobjectivebounds: | INITIALOBJECTIVEBOUNDSSTART numberofobjbounds GREATERTHAN
    objboundlist INITIALOBJECTIVEBOUNDSEND;

numberofobjbounds: NUMBEROFOBJATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = $3;
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
};

objboundlist: | objboundlist initobjbound;

initobjbound: objboundstart initobjboundattlist initobjboundend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
};

objboundstart: OBJSTART
{	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
};

initobjboundattlist: | initobjboundattlist initobjboundatt;

initobjboundatt: initobjboundidxatt | initobjvaluelowerboundatt | initobjvalueupperboundatt;

initobjboundidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ($3 >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-$3 > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->idx = $3;
};

initobjvaluelowerboundatt: LBVALUEATT ATTRIBUTETEXT
{	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = os_strtod($2, NULL);
}
QUOTE;

initobjvalueupperboundatt: UBVALUEATT ATTRIBUTETEXT
{	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = os_strtod($2, NULL);
}
QUOTE;

initobjboundend: GREATERTHAN OBJEND | ENDOFELEMENT;



otherobjectiveoptionlist: | otherobjectiveoptionlist otherobjectiveoption;

otherobjectiveoption: otherobjectiveoptionstart otherobjectiveoptionsattlist restofotherobjectiveoption;

otherobjectiveoptionstart: OTHERSTART 
{	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
};

otherobjectiveoptionsattlist: | otherobjectiveoptionsattlist otherobjectiveoptionsatt;

otherobjectiveoptionsatt:
     otherobjectiveoptionnumberofobj
   | otherobjectiveoptionname
   | otherobjectiveoptionvalue
   | otherobjectiveoptionsolver
   | otherobjectiveoptioncategory
   | otherobjectiveoptiontype
   | otherobjectiveoptiondescription;

otherobjectiveoptionnumberofobj: NUMBEROFOBJATT QUOTE INTEGER QUOTE
{ 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfObj attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfObj = 0;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options must be nonnegative");
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj = $3;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj = new OtherObjOption*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[i] = new OtherObjOption();
};

otherobjectiveoptionname: NAMEATT ATTRIBUTETEXT 
{	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = $2;
}
QUOTE;


otherobjectiveoptionvalue: VALUEATT ATTRIBUTETEXT 
{	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = $2;
}
QUOTE;


otherobjectiveoptionsolver: SOLVERATT ATTRIBUTETEXT 
{	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = $2;
}
QUOTE;


otherobjectiveoptioncategory: CATEGORYATT ATTRIBUTETEXT 
{	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = $2;
}
QUOTE;


otherobjectiveoptiontype: TYPEATT ATTRIBUTETEXT 
{	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = $2;
}
QUOTE;


otherobjectiveoptiondescription: DESCRIPTIONATT ATTRIBUTETEXT 
{	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = $2;
}
QUOTE;



restofotherobjectiveoption: GREATERTHAN otherobjectiveoptionsobjlist OTHEREND
{ 	if (parserData->numberOfObj < osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "not enough <obj> entries in <other> variable element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherObjectiveOptions++;
};

otherobjectiveoptionsobjlist: | otherobjectiveoptionsobjlist otherobjectiveoptionsobj;

otherobjectiveoptionsobj: otherobjectiveoptionsobjstart otherobjoptionattlist otherobjoptionend
{	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
};

otherobjectiveoptionsobjstart: OBJSTART 
{	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
};

otherobjoptionattlist: | otherobjoptionattlist otherobjoptionatt;

otherobjoptionatt:
     otherobjoptionidx
   | otherobjoptionvalue
   | otherobjoptionlbvalue
   | otherobjoptionubvalue;

otherobjoptionidx: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ($3 >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-$3 > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index exceeds upper limit");
	};
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->idx = $3;
};


otherobjoptionvalue: VALUEATT ATTRIBUTETEXT 
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = $2;
}
QUOTE;


otherobjoptionlbvalue: LBVALUEATT ATTRIBUTETEXT 
{	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = $2;
}
QUOTE;


otherobjoptionubvalue: UBVALUEATT ATTRIBUTETEXT 
{	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = $2;
}
QUOTE;


otherobjoptionend: GREATERTHAN VAREND | ENDOFELEMENT;


constraints: | constraintsstart numberofotherconstraintsatt restofconstraints;

constraintsstart: CONSTRAINTSSTART
{	osoption->optimization->constraints = new ConstraintOption();
};

numberofotherconstraintsatt: | NUMBEROFOTHERCONSTRAINTOPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = $3;
	osoption->optimization->constraints->other = new OtherConstraintOption*[$3];
	for (int i= 0; i < $3; i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
};

restofconstraints: GREATERTHAN initialconstraintvalues initialdualvalues
   otherconstraintoptionlist CONSTRAINTSEND
   | ENDOFELEMENT;

initialconstraintvalues: | INITIALCONSTRAINTVALUESSTART numberofconval GREATERTHAN
    conlist INITIALCONSTRAINTVALUESEND;

numberofconval: NUMBEROFCONATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = $3;
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
};

conlist: | conlist initconvalue;

initconvalue: constart initconvalueattlist initconvalueend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
};

constart: CONSTART
{	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
};

initconvalueattlist: | initconvalueattlist initconvalueatt;

initconvalueatt: initconvalueidxatt | initconvaluevalueatt;

initconvalueidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ($3 > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->idx = $3;
};


initconvaluevalueatt: VALUEATT ATTRIBUTETEXT
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = os_strtod($2, NULL);
}
QUOTE;

initconvalueend: GREATERTHAN CONEND | ENDOFELEMENT;


initialdualvalues: | INITIALDUALVALUESSTART numberofduals GREATERTHAN
    duallist INITIALDUALVALUESEND;

numberofduals: NUMBEROFCONATT QUOTE INTEGER QUOTE
{	if ($3 <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = $3;
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
};

duallist: | duallist initdualvalue;

initdualvalue: dualstart initdualvalueattlist initdualvalueend
{	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
};

dualstart: CONSTART
{	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
};

initdualvalueattlist: | initdualvalueattlist initdualvalueatt;

initdualvalueatt: initdualvalueidxatt | initdualvaluelowerboundatt | initdualvalueupperboundatt;

initdualvalueidxatt: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ($3 > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->idx = $3;
};

initdualvaluelowerboundatt: LBDUALVALUEATT ATTRIBUTETEXT
{	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = os_strtod($2, NULL);
}
QUOTE;

initdualvalueupperboundatt: UBDUALVALUEATT ATTRIBUTETEXT
{	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp($2,"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = OSDBL_MAX;
	else if (strcmp($2,"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = os_strtod($2, NULL);
}
QUOTE;


initdualvalueend: GREATERTHAN CONEND | ENDOFELEMENT;


otherconstraintoptionlist: | otherconstraintoptionlist otherconstraintoption;

otherconstraintoption: otherconstraintoptionstart otherconstraintoptionsattlist restofotherconstraintoption;

otherconstraintoptionstart: OTHERSTART
{	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
};

otherconstraintoptionsattlist: | otherconstraintoptionsattlist otherconstraintoptionsatt;

otherconstraintoptionsatt:
     otherconstraintoptionnumberofcon 
   | otherconstraintoptionname
   | otherconstraintoptionvalue
   | otherconstraintoptionsolver
   | otherconstraintoptioncategory
   | otherconstraintoptiontype
   | otherconstraintoptiondescription;

otherconstraintoptionnumberofcon: NUMBEROFCONATT QUOTE INTEGER QUOTE 
{ 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfCon attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfCon = 0;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options must be nonnegative");
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon = $3;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con = new OtherConOption*[$3];
	for (int i = 0; i < $3; i++)
		osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[i] = new OtherConOption();
};

otherconstraintoptionname: NAMEATT ATTRIBUTETEXT 
{	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = $2;
}
QUOTE;

otherconstraintoptionvalue: VALUEATT ATTRIBUTETEXT 
{	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = $2;
}
QUOTE;

otherconstraintoptionsolver: SOLVERATT ATTRIBUTETEXT 
{	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = $2;
}
QUOTE;

otherconstraintoptioncategory: CATEGORYATT ATTRIBUTETEXT 
{	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = $2;
}
QUOTE;

otherconstraintoptiontype: TYPEATT ATTRIBUTETEXT 
{	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = $2;
}
QUOTE;

otherconstraintoptiondescription: DESCRIPTIONATT ATTRIBUTETEXT 
{	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = $2;
}
QUOTE;


restofotherconstraintoption: GREATERTHAN otherconstraintoptionsconlist OTHEREND
{ 	if (parserData->numberOfCon < osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
		osolerror(NULL, osoption, parserData, "not enough <con> entries in <other> constraint element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherConstraintOptions++;
};

otherconstraintoptionsconlist: | otherconstraintoptionsconlist otherconstraintoptionscon;

otherconstraintoptionscon: otherconstraintoptionsconstart otherconoptionattlist otherconoptionend
{	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
};

otherconstraintoptionsconstart: CONSTART 
{	if (parserData->numberOfCon >= osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many <con> entries in <other> constraint element");
};

otherconoptionattlist: | otherconoptionattlist otherconoptionatt;

otherconoptionatt:
     otherconoptionidx
   | otherconoptionvalue
   | otherconoptionlbvalue
   | otherconoptionubvalue;

otherconoptionidx: IDXATT QUOTE INTEGER QUOTE
{	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ($3 >= parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index exceeds upper limit");
	};
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->idx = $3;
};


otherconoptionvalue: VALUEATT ATTRIBUTETEXT 
{	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = $2;
}
QUOTE;


otherconoptionlbvalue: LBVALUEATT ATTRIBUTETEXT 
{	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = $2;
}
QUOTE;

otherconoptionubvalue: UBVALUEATT ATTRIBUTETEXT 
{	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = $2;
}
QUOTE;

otherconoptionend: GREATERTHAN CONEND | ENDOFELEMENT;


solveroptions: | solveroptionsstart numberofsolveroptionsatt GREATERTHAN solveroptionlist SOLVEROPTIONSEND
{	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
};

solveroptionsstart: SOLVEROPTIONSSTART
{	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
};

numberofsolveroptionsatt: NUMBEROFSOLVEROPTIONSATT QUOTE INTEGER QUOTE
{	if ($3 < 0)
		osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = $3;
	osoption->optimization->solverOptions->solverOption = new SolverOption*[$3];
	for (int i=0; i < $3; i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
};

solveroptionlist: | solveroptionlist solveroption;

solveroption: SOLVEROPTIONSTART
{	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
}
solveroptionattlist solveroptionend
{	if (!parserData->solverOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->solverOptionNamePresent = false;
	parserData->solverOptionValuePresent = false;
	parserData->solverOptionSolverPresent = false;
	parserData->solverOptionCategoryPresent = false;
	parserData->solverOptionTypePresent = false;
	parserData->solverOptionDescriptionPresent = false;
	parserData->numberOfSolverOptions++;
};

solveroptionattlist: | solveroptionattlist solveroptionatt;

solveroptionatt:
     solveroptionname
   | solveroptionvalue
   | solveroptionsolver
   | solveroptioncategory
   | solveroptiontype
   | solveroptiondescription;


solveroptionname: NAMEATT ATTRIBUTETEXT
{	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = $2;
	}
}
QUOTE;

solveroptionvalue: VALUEATT ATTRIBUTETEXT
{	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = $2;
	}
}
QUOTE;

solveroptionsolver: SOLVERATT ATTRIBUTETEXT
{	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = $2;
	}
}
QUOTE;

solveroptioncategory: CATEGORYATT ATTRIBUTETEXT
{	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = $2;
	}
}
QUOTE;

solveroptiontype: TYPEATT ATTRIBUTETEXT
{	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = $2;
	}
}
QUOTE;

solveroptiondescription: DESCRIPTIONATT ATTRIBUTETEXT
{	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = $2;
	}
}
QUOTE;


solveroptionend: GREATERTHAN SOLVEROPTIONEND | ENDOFELEMENT;



//quote: xmlWhiteSpace QUOTE;
//
//xmlWhiteSpaceChar: ' '
//				| '\t'
//				| '\r'
//				| '\n' ;
//
//xmlWhiteSpace:
//			| xmlWhiteSpace xmlWhiteSpaceChar ;


%%

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, const char* errormsg )
{
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "Input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "See line number: " << osolget_lineno( scanner) << std::endl;
	outStr << "The offending text is: " << osolget_text ( scanner ) << std::endl;
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osollex_destroy( scanner);
	throw ErrorClass( error);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, OSoLParserData *parserData) throw(ErrorClass){
	try{
		osol_scan_string( parsestring, scanner);
		osolset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osolparse( osoption,  parserData) != 0) {
			//osollex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSoL file");
		 }
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg);
	}
} //end yygetOSOption

