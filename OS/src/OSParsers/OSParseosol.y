/** @file parseosol.y
 * 
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.1, 10/07/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

%{

 
  

#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include <iostream>
#include <sstream> 


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
%token FROMATT TOATT MAKECOPYATT SOLVERATT CATEGORYATT TYPEATT;
%token NUMBEROFPROCESSESATT NUMBEROFSOLVEROPTIONSATT;
%token NUMBEROFVARIABLESATT NUMBEROFOBJECTIVESATT NUMBEROFCONSTRAINTSATT;
%token NUMBEROFOTHERVARIABLEOPTIONSATT NUMBEROFOTHEROBJECTIVEOPTIONSATT;
%token NUMBEROFOTHERCONSTRAINTOPTIONSATT;
%token NUMBEROFVARATT NUMBEROFOBJATT NUMBEROFCONATT;
%token NAMEATT IDXATT VALUEATT UNITATT DESCRIPTIONATT LBVALUEATT UBVALUEATT;

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
%token DIRECTORIESTOMAKESTART DIRECTORIESTOMAKEEND FILESTOCREATESTART FILESTOCREATEEND;
%token DIRECTORIESTODELETESTART DIRECTORIESTODELETEEND FILESTODELETESTART FILESTODELETEEND;
%token  INPUTDIRECTORIESTOMOVESTART  INPUTDIRECTORIESTOMOVEEND  INPUTFILESTOMOVESTART  INPUTFILESTOMOVEEND;
%token OUTPUTDIRECTORIESTOMOVESTART OUTPUTDIRECTORIESTOMOVEEND OUTPUTFILESTOMOVESTART OUTPUTFILESTOMOVEEND;
%token PROCESSESTOKILLSTART PROCESSESTOKILLEND PROCESSSTART PROCESSEND;
%token VARIABLESSTART VARIABLESEND;
%token INITIALVARIABLEVALUESSTART INITIALVARIABLEVALUESEND VARSTART VAREND;
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

osolcontent: osolgeneral osolsystem osolservice osoljob osoloptimization ;

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
	}
}; 

locationtypeatt: | LOCATIONTYPEATT ATTRIBUTETEXT {osoption->general->instanceLocation->locationType = $2;} QUOTE;

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
	}
}; 

transporttypeatt: | TRANSPORTTYPEATT ATTRIBUTETEXT {osoption->general->contact->transportType = $2;} QUOTE;

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
{	osoption->general->otherOptions->numberOfOtherOptions = $3;
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
	{	parserData-> minDiskSpacePresent = true;	
		osoption->system->minDiskSpace = new MinDiskSpace();
	}
}; 

mindiskspaceunit: | UNITATT ATTRIBUTETEXT {osoption->system->minDiskSpace->unit = $2;} QUOTE;

mindiskspacebody: ENDOFELEMENT
	| GREATERTHAN MINDISKSPACEEND 
	| GREATERTHAN DOUBLE  {osoption->system->minDiskSpace->value = $2;} MINDISKSPACEEND
	| GREATERTHAN INTEGER {osoption->system->minDiskSpace->value = $2;} MINDISKSPACEEND;


minmemorysize: minmemorysizehead minmemoryunit minmemorysizebody;

minmemorysizehead: MINMEMORYSIZESTART 
{	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData-> minMemorySizePresent = true;	
		osoption->system->minMemorySize = new MinMemorySize();
	}
}; 

minmemoryunit: | UNITATT ATTRIBUTETEXT {osoption->system->minMemorySize->unit = $2;} QUOTE;

minmemorysizebody: ENDOFELEMENT
	| GREATERTHAN MINMEMORYSIZEEND 
	| GREATERTHAN DOUBLE  {osoption->system->minMemorySize->value = $2;} MINMEMORYSIZEEND
	| GREATERTHAN INTEGER {osoption->system->minMemorySize->value = $2;} MINMEMORYSIZEEND;


mincpuspeed: mincpuspeedhead mincpuspeedunit mincpuspeedbody;

mincpuspeedhead: MINCPUSPEEDSTART 
{	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData-> minCPUSpeedPresent = true;	
		osoption->system->minCPUSpeed = new MinCPUSpeed();
	}
}; 
 
mincpuspeedunit: | UNITATT ATTRIBUTETEXT {osoption->system->minCPUSpeed->unit = $2;} QUOTE;

mincpuspeedbody: ENDOFELEMENT
	| GREATERTHAN MINCPUSPEEDEND
	| GREATERTHAN DOUBLE  {osoption->system->minCPUSpeed->value = $2;} MINCPUSPEEDEND
	| GREATERTHAN INTEGER {osoption->system->minCPUSpeed->value = $2;} MINCPUSPEEDEND;


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
	| GREATERTHAN INTEGER {osoption->system->minCPUNumber = $2;} MINCPUNUMBEREND;


othersystemoptions: othersystemoptionshead numberofothersystemoptions GREATERTHAN othersystemoptionsbody;

othersystemoptionshead: OTHEROPTIONSSTART
{	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();	
		osoption->system->otherOptions->other = new OtherOption*();	
	}
}; 
 
numberofothersystemoptions: NUMBEROFOTHEROPTIONSATT QUOTE INTEGER QUOTE
{	osoption->system->otherOptions->numberOfOtherOptions = $3;
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
    othersystemattributes othersystemoptionsend
{	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
};

othersystemattributes: | othersystemattributes othersystemattribute;

othersystemattribute: systemoptionnameatt systemoptionvalueatt systemoptiondescriptionatt;

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

othersystemoptionsend: ENDOFELEMENT | GREATERTHAN OTHEREND;


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

servicetype: servicetypehead | servicetypebody;

servicetypehead: SERVICETYPESTART 
{	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;	
	}
}; 

servicetypebody: ENDOFELEMENT
	| GREATERTHAN SERVICETYPEEND
	| GREATERTHAN INTEGER {osoption->service->type = $2;} SERVICETYPEEND;

otherserviceoptions: otherserviceoptionshead numberofotherserviceoptions GREATERTHAN otherserviceoptionsbody;

otherserviceoptionshead: OTHEROPTIONSSTART
{	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();	
		osoption->service->otherOptions->other = new OtherOption*();	
	}
}; 

numberofotherserviceoptions: NUMBEROFOTHEROPTIONSATT QUOTE INTEGER QUOTE
{	osoption->service->otherOptions->numberOfOtherOptions = $3;
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

otherserviceattribute: serviceoptionnameatt serviceoptionvalueatt serviceoptiondescriptionatt;

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

serviceoptionvalueatt: | VALUEATT ATTRIBUTETEXT 
{	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = $2;	
	}
}
QUOTE;

serviceoptiondescriptionatt: | DESCRIPTIONATT ATTRIBUTETEXT 
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


osoljob: 
	| JOBSTART GREATERTHAN jobcontent JOBEND
	| JOBSTART ENDOFELEMENT;

jobcontent: | jobcontent joboption; 

joboption: maxtime | scheduledstarttime | dependencies | requireddirectories | requiredfiles
| directoriestomake | filestocreate | inputdirectoriestomove | inputfilestomove | outputdirectoriestomove 
| outputfilestomove | filestodelete | directoriestodelete | processestokill | otherjoboptions;

maxtime: MAXTIMESTART maxtimeunit GREATERTHAN ELEMENTTEXT MAXTIMEEND
{
};

maxtimeunit: | UNITATT ATTRIBUTETEXT QUOTE
{
};

scheduledstarttime: emptystarttime | nonemptystarttime;

emptystarttime: SCHEDULEDSTARTTIMESTART ENDOFELEMENT
        |   SCHEDULEDSTARTTIMESTART GREATERTHAN SCHEDULEDSTARTTIMEEND
{
};

nonemptystarttime: SCHEDULEDSTARTTIMESTART GREATERTHAN ELEMENTTEXT SCHEDULEDSTARTTIMEEND
{
};

dependencies: DEPENDENCIESSTART numberofjobidsatt dependencieslist DEPENDENCIESEND;

numberofjobidsatt: NUMBEROFJOBIDSATT ATTRIBUTETEXT QUOTE
{
};

dependencieslist: | dependencieslist dependencyjobid;


dependencyjobid: JOBIDSTART GREATERTHAN ELEMENTTEXT JOBIDEND
{
};

requireddirectories: REQUIREDDIRECTORIESSTART numberofreqdirpathsatt reqdirpathlist 
   REQUIREDDIRECTORIESEND;

numberofreqdirpathsatt: NUMBEROFPATHSATT ATTRIBUTETEXT QUOTE
{
};

reqdirpathlist: | reqdirpathlist reqdirpath;

reqdirpath: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
};

requiredfiles: REQUIREDFILESSTART numberofreqfilpathsatt GREATERTHAN reqfilpathlist 
   REQUIREDFILESEND;

numberofreqfilpathsatt: NUMBEROFPATHSATT ATTRIBUTETEXT QUOTE
{
};

reqfilpathlist: | reqfilpathlist reqfilpath;

reqfilpath: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
};

directoriestomake: DIRECTORIESTOMAKESTART numberofdirtomakepathsatt GREATERTHAN dirtomakepathlist
   DIRECTORIESTOMAKEEND;

numberofdirtomakepathsatt: NUMBEROFPATHSATT ATTRIBUTETEXT QUOTE
{
};

dirtomakepathlist: | dirtomakepathlist dirtomakepath;

dirtomakepath: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
};

filestocreate: FILESTOCREATESTART numberoffilestomakepathsatt GREATERTHAN filestomakepathlist
   FILESTOCREATEEND;

numberoffilestomakepathsatt: NUMBEROFPATHSATT ATTRIBUTETEXT QUOTE
{
};

filestomakepathlist: | filestomakepathlist filestomakepath;

filestomakepath: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
};

inputdirectoriestomove: INPUTDIRECTORIESTOMOVESTART numberofindirtomovepathpairsatt 
   GREATERTHAN indirtomovepathpairlist INPUTDIRECTORIESTOMOVEEND;

numberofindirtomovepathpairsatt: NUMBEROFPATHPAIRSATT ATTRIBUTETEXT QUOTE
{
};

indirtomovepathpairlist: | indirtomovepathpairlist indirtomovepathpair;

indirtomovepathpair: PATHPAIRSTART indirtomovepathpairattlist indirtomovepathpairend
{
};

indirtomovepathpairattlist: | indirtomovepathpairattlist indirtomovepathpairatt;

indirtomovepathpairatt: indirtomovefromatt | indirtomovetoatt | indirtomovemakecopyatt;

indirtomovefromatt: FROMATT ATTRIBUTETEXT QUOTE
{
};

indirtomovetoatt: TOATT ATTRIBUTETEXT QUOTE
{
};

indirtomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT QUOTE
{
};

indirtomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


inputfilestomove: INPUTFILESTOMOVESTART numberofinfilestomovepathpairsatt 
   GREATERTHAN infilestomovepathpairlist INPUTFILESTOMOVEEND;

numberofinfilestomovepathpairsatt: NUMBEROFPATHPAIRSATT ATTRIBUTETEXT QUOTE
{
};

infilestomovepathpairlist: | infilestomovepathpairlist infilestomovepathpair;

infilestomovepathpair: PATHPAIRSTART infilestomovepathpairattlist infilestomovepathpairend
{
};

infilestomovepathpairattlist: | infilestomovepathpairattlist infilestomovepathpairatt;

infilestomovepathpairatt: infilestomovefromatt | infilestomovetoatt | infilestomovemakecopyatt;

infilestomovefromatt: FROMATT ATTRIBUTETEXT QUOTE
{
};

infilestomovetoatt: TOATT ATTRIBUTETEXT QUOTE
{
};

infilestomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT QUOTE
{
};

infilestomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


outputdirectoriestomove: OUTPUTDIRECTORIESTOMOVESTART numberofoutdirtomovepathpairsatt 
   GREATERTHAN outdirtomovepathpairlist OUTPUTDIRECTORIESTOMOVEEND;

numberofoutdirtomovepathpairsatt: NUMBEROFPATHPAIRSATT ATTRIBUTETEXT QUOTE
{
};

outdirtomovepathpairlist: | outdirtomovepathpairlist outdirtomovepathpair;

outdirtomovepathpair: PATHPAIRSTART outdirtomovepathpairattlist outdirtomovepathpairend
{
};

outdirtomovepathpairattlist: | outdirtomovepathpairattlist outdirtomovepathpairatt;

outdirtomovepathpairatt: outdirtomovefromatt | outdirtomovetoatt | outdirtomovemakecopyatt;

outdirtomovefromatt: FROMATT ATTRIBUTETEXT QUOTE
{
};

outdirtomovetoatt: TOATT ATTRIBUTETEXT QUOTE
{
};

outdirtomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT QUOTE
{
};

outdirtomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


outputfilestomove: OUTPUTFILESTOMOVESTART numberofoutfilestomovepathpairsatt 
   GREATERTHAN outfilestomovepathpairlist OUTPUTFILESTOMOVEEND;

numberofoutfilestomovepathpairsatt: NUMBEROFPATHPAIRSATT ATTRIBUTETEXT QUOTE
{
};

outfilestomovepathpairlist: | outfilestomovepathpairlist outfilestomovepathpair;

outfilestomovepathpair: PATHPAIRSTART outfilestomovepathpairattlist outfilestomovepathpairend
{
};

outfilestomovepathpairattlist: | outfilestomovepathpairattlist outfilestomovepathpairatt;

outfilestomovepathpairatt: outfilestomovefromatt | outfilestomovetoatt | outfilestomovemakecopyatt;

outfilestomovefromatt: FROMATT ATTRIBUTETEXT QUOTE
{
};

outfilestomovetoatt: TOATT ATTRIBUTETEXT QUOTE
{
};

outfilestomovemakecopyatt: MAKECOPYATT ATTRIBUTETEXT QUOTE
{
};

outfilestomovepathpairend: GREATERTHAN PATHPAIREND | ENDOFELEMENT;



filestodelete: FILESTODELETESTART numberoffilestodeletepathsatt GREATERTHAN filestodeletepathlist
   FILESTODELETEEND;

numberoffilestodeletepathsatt: NUMBEROFPATHSATT ATTRIBUTETEXT QUOTE
{
};

filestodeletepathlist: | filestodeletepathlist filestodeletepath;

filestodeletepath: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
};

directoriestodelete: DIRECTORIESTODELETESTART numberofdirtodeletepathsatt GREATERTHAN dirtodeletepathlist
   DIRECTORIESTODELETEEND;

numberofdirtodeletepathsatt: NUMBEROFPATHSATT ATTRIBUTETEXT QUOTE
{
};

dirtodeletepathlist: | dirtodeletepathlist dirtodeletepath;

dirtodeletepath: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
};


processestokill: PROCESSESTOKILLSTART numberofprocesstokillatt GREATERTHAN processestokilllist
   PROCESSESTOKILLEND;

numberofprocesstokillatt: NUMBEROFPROCESSESATT ATTRIBUTETEXT QUOTE
{
};

processestokilllist: | processestokilllist processtokill;

processtokill: PROCESSSTART GREATERTHAN ELEMENTTEXT PROCESSEND
{
};


otherjoboptions: OTHEROPTIONSSTART numberofotherjoboptions GREATERTHAN otherjoboptionslist OTHEROPTIONSEND;

numberofotherjoboptions: NUMBEROFOTHEROPTIONSATT ATTRIBUTETEXT QUOTE
{
};

otherjoboptionslist: | otherjoboptionslist otherjoboption;

otherjoboption: OTHERSTART otherjobattributes otherjoboptionsend;

otherjobattributes: | otherjobattributes otherjobattribute;

otherjobattribute: joboptionnameatt joboptionvalueatt joboptiondescriptionatt;

joboptionnameatt: NAMEATT ATTRIBUTETEXT QUOTE
{
};

joboptionvalueatt: | VALUEATT ATTRIBUTETEXT QUOTE
{
};

joboptiondescriptionatt: | DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};

otherjoboptionsend: ENDOFELEMENT | GREATERTHAN OTHEREND
{
};


osoloptimization: | OPTIMIZATIONSTART optimizationattlist restofoptimization;

optimizationattlist: | optimizationattlist optimizationatt;

optimizationatt: optimizationnvar | optimizationncon | optimizationnobj;

optimizationnvar: NUMBEROFVARIABLESATT ATTRIBUTETEXT QUOTE
{
};

optimizationncon: NUMBEROFCONSTRAINTSATT ATTRIBUTETEXT QUOTE
{
};

optimizationnobj: NUMBEROFOBJECTIVESATT ATTRIBUTETEXT QUOTE
{
};

restofoptimization: GREATERTHAN optimizationcontent OPTIMIZATIONEND | ENDOFELEMENT;

optimizationcontent: variables objectives constraints solveroptions;

variables: | VARIABLESSTART numberofothervariablesatt restofvariables;

numberofothervariablesatt: | NUMBEROFOTHERVARIABLEOPTIONSATT ATTRIBUTETEXT QUOTE
{
};

restofvariables: GREATERTHAN initialvariablevalues othervariableoptions VARIABLESEND
   | ENDOFELEMENT;

initialvariablevalues: | INITIALVARIABLEVALUESSTART NUMBEROFVARATT ATTRIBUTETEXT QUOTE GREATERTHAN 
    varlist INITIALVARIABLEVALUESEND;

varlist: | varlist initvarvalue;

initvarvalue: VARSTART initvarvalueattlist initvarvalueend;

initvarvalueattlist: | initvarvalueattlist initvarvalueatt;

initvarvalueatt: initvarvalueidxatt | initvarvaluevalueatt;

initvarvalueidxatt: IDXATT ATTRIBUTETEXT QUOTE
{
};

initvarvaluevalueatt: VALUEATT ATTRIBUTETEXT QUOTE
{
};

initvarvalueend: GREATERTHAN VAREND | ENDOFELEMENT;


othervariableoptions: | OTHERSTART othervariableoptionsattlist restofothervariableoptions;

othervariableoptionsattlist: | othervariableoptionsattlist othervariableoptionsatt;

othervariableoptionsatt: 
     othervariableoptionnumberofvar 
   | othervariableoptionname
   | othervariableoptionvalue
   | othervariableoptionsolver
   | othervariableoptioncategory
   | othervariableoptiontype
   | othervariableoptiondescription;

othervariableoptionnumberofvar: NUMBEROFVARATT ATTRIBUTETEXT QUOTE
{
};

othervariableoptionname: NAMEATT ATTRIBUTETEXT QUOTE
{
};

othervariableoptionvalue: VALUEATT ATTRIBUTETEXT QUOTE
{
};

othervariableoptionsolver: SOLVERATT ATTRIBUTETEXT QUOTE
{
};

othervariableoptioncategory: CATEGORYATT ATTRIBUTETEXT QUOTE
{
};

othervariableoptiontype: TYPEATT ATTRIBUTETEXT QUOTE
{
};

othervariableoptiondescription: DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};


restofothervariableoptions: GREATERTHAN othervariableoptionsvarlist OTHEREND;

othervariableoptionsvarlist: VARSTART othervaroptionattlist othervaroptionend;

othervaroptionattlist: | othervaroptionattlist othervaroptionatt;

othervaroptionatt: 
     othervaroptionidx
   | othervaroptionvalue
   | othervaroptionlbvalue
   | othervaroptionubvalue;

othervaroptionidx: IDXATT ATTRIBUTETEXT QUOTE
{
};

othervaroptionvalue: VALUEATT ATTRIBUTETEXT QUOTE
{
};

othervaroptionlbvalue: LBVALUEATT ATTRIBUTETEXT QUOTE
{
};

othervaroptionubvalue: UBVALUEATT ATTRIBUTETEXT QUOTE
{
};

othervaroptionend: GREATERTHAN VAREND | ENDOFELEMENT;

objectives: | OBJECTIVESSTART numberofotherobjectivesatt restofobjectives;

numberofotherobjectivesatt: | NUMBEROFOTHEROBJECTIVEOPTIONSATT ATTRIBUTETEXT QUOTE
{
};

restofobjectives: GREATERTHAN initialobjectivevalues initialobjectivebounds
   otherobjectiveoptions OBJECTIVESEND
   | ENDOFELEMENT;


initialobjectivevalues: | INITIALOBJECTIVEVALUESSTART NUMBEROFOBJATT ATTRIBUTETEXT QUOTE GREATERTHAN
    objvaluelist INITIALOBJECTIVEVALUESEND;

objvaluelist: | objvaluelist initobjvalue;

initobjvalue: OBJSTART initobjvalueattlist initobjvalueend;

initobjvalueattlist: | initobjvalueattlist initobjvalueatt;

initobjvalueatt: initobjvalueidxatt | initobjvaluevalueatt;

initobjvalueidxatt: IDXATT ATTRIBUTETEXT QUOTE
{
};

initobjvaluevalueatt: VALUEATT ATTRIBUTETEXT QUOTE
{
};

initobjvalueend: GREATERTHAN OBJEND | ENDOFELEMENT;


initialobjectivebounds: | INITIALOBJECTIVEBOUNDSSTART NUMBEROFOBJATT ATTRIBUTETEXT QUOTE GREATERTHAN
    objboundlist INITIALOBJECTIVEBOUNDSEND;

objboundlist: | objboundlist initobjbound;

initobjbound: OBJSTART initobjboundattlist initobjboundend;

initobjboundattlist: | initobjboundattlist initobjboundatt;

initobjboundatt: initobjboundidxatt | initobjboundvalueatt;

initobjboundidxatt: IDXATT ATTRIBUTETEXT QUOTE
{
};

initobjboundvalueatt: VALUEATT ATTRIBUTETEXT QUOTE
{
};

initobjboundend: GREATERTHAN OBJEND | ENDOFELEMENT;


otherobjectiveoptions: | OTHERSTART otherobjectiveoptionsattlist restofotherobjectiveoptions;

otherobjectiveoptionsattlist: | otherobjectiveoptionsattlist otherobjectiveoptionsatt;

otherobjectiveoptionsatt: 
     otherobjectiveoptionnumberofvar 
   | otherobjectiveoptionname
   | otherobjectiveoptionvalue
   | otherobjectiveoptionsolver
   | otherobjectiveoptioncategory
   | otherobjectiveoptiontype
   | otherobjectiveoptiondescription;

otherobjectiveoptionnumberofvar: NUMBEROFOBJATT ATTRIBUTETEXT QUOTE
{
};

otherobjectiveoptionname: NAMEATT ATTRIBUTETEXT QUOTE
{
};

otherobjectiveoptionvalue: VALUEATT ATTRIBUTETEXT QUOTE
{
};

otherobjectiveoptionsolver: SOLVERATT ATTRIBUTETEXT QUOTE
{
};

otherobjectiveoptioncategory: CATEGORYATT ATTRIBUTETEXT QUOTE
{
};

otherobjectiveoptiontype: TYPEATT ATTRIBUTETEXT QUOTE
{
};

otherobjectiveoptiondescription: DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};


restofotherobjectiveoptions: GREATERTHAN otherobjectiveoptionsvarlist OTHEREND;

otherobjectiveoptionsvarlist: OBJSTART otherobjoptionattlist otherobjoptionend;

otherobjoptionattlist: | otherobjoptionattlist otherobjoptionatt;

otherobjoptionatt: 
     otherobjoptionidx
   | otherobjoptionvalue
   | otherobjoptionlbvalue
   | otherobjoptionubvalue;

otherobjoptionidx: IDXATT ATTRIBUTETEXT QUOTE
{
};

otherobjoptionvalue: VALUEATT ATTRIBUTETEXT QUOTE
{
};

otherobjoptionlbvalue: LBVALUEATT ATTRIBUTETEXT QUOTE
{
};

otherobjoptionubvalue: UBVALUEATT ATTRIBUTETEXT QUOTE
{
};

otherobjoptionend: GREATERTHAN VAREND | ENDOFELEMENT;

constraints: | CONSTRAINTSSTART numberofotherconstraintsatt restofconstraints;

numberofotherconstraintsatt: | NUMBEROFOTHERCONSTRAINTOPTIONSATT ATTRIBUTETEXT QUOTE
{
};

restofconstraints: GREATERTHAN initialconstraintvalues initialdualvalues
   otherconstraintoptions CONSTRAINTSEND
   | ENDOFELEMENT;

initialconstraintvalues: | INITIALCONSTRAINTVALUESSTART NUMBEROFCONATT ATTRIBUTETEXT QUOTE GREATERTHAN 
    conlist INITIALCONSTRAINTVALUESEND;

conlist: | conlist initconvalue;

initconvalue: CONSTART initconvalueattlist initconvalueend;

initconvalueattlist: | initconvalueattlist initconvalueatt;

initconvalueatt: initconvalueidxatt | initconvaluevalueatt;

initconvalueidxatt: IDXATT ATTRIBUTETEXT QUOTE
{
};

initconvaluevalueatt: VALUEATT ATTRIBUTETEXT QUOTE
{
};

initconvalueend: GREATERTHAN CONEND | ENDOFELEMENT;


initialdualvalues: | INITIALDUALVALUESSTART NUMBEROFCONATT ATTRIBUTETEXT QUOTE GREATERTHAN 
duallist INITIALDUALVALUESEND;

duallist: | duallist initdualvalue;

initdualvalue: CONSTART initdualvalueattlist initdualvalueend;

initdualvalueattlist: | initdualvalueattlist initdualvalueatt;

initdualvalueatt: initdualvalueidxatt | initdualvaluevalueatt;

initdualvalueidxatt: IDXATT ATTRIBUTETEXT QUOTE
{
};

initdualvaluevalueatt: VALUEATT ATTRIBUTETEXT QUOTE
{
};

initdualvalueend: GREATERTHAN CONEND | ENDOFELEMENT;


otherconstraintoptions: | OTHERSTART otherconstraintoptionsattlist restofotherconstraintoptions;

otherconstraintoptionsattlist: | otherconstraintoptionsattlist otherconstraintoptionsatt;

otherconstraintoptionsatt: 
     otherconstraintoptionnumberofvar 
   | otherconstraintoptionname
   | otherconstraintoptionvalue
   | otherconstraintoptionsolver
   | otherconstraintoptioncategory
   | otherconstraintoptiontype
   | otherconstraintoptiondescription;

otherconstraintoptionnumberofvar: NUMBEROFCONATT ATTRIBUTETEXT QUOTE
{
};

otherconstraintoptionname: NAMEATT ATTRIBUTETEXT QUOTE
{
};

otherconstraintoptionvalue: VALUEATT ATTRIBUTETEXT QUOTE
{
};

otherconstraintoptionsolver: SOLVERATT ATTRIBUTETEXT QUOTE
{
};

otherconstraintoptioncategory: CATEGORYATT ATTRIBUTETEXT QUOTE
{
};

otherconstraintoptiontype: TYPEATT ATTRIBUTETEXT QUOTE
{
};

otherconstraintoptiondescription: DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};


restofotherconstraintoptions: GREATERTHAN otherconstraintoptionsvarlist OTHEREND;

otherconstraintoptionsvarlist: CONSTART otherconoptionattlist otherconoptionend;

otherconoptionattlist: | otherconoptionattlist otherconoptionatt;

otherconoptionatt: 
     otherconoptionidx
   | otherconoptionvalue
   | otherconoptionlbvalue
   | otherconoptionubvalue;

otherconoptionidx: IDXATT ATTRIBUTETEXT QUOTE
{
};

otherconoptionvalue: VALUEATT ATTRIBUTETEXT QUOTE
{
};

otherconoptionlbvalue: LBVALUEATT ATTRIBUTETEXT QUOTE
{
};

otherconoptionubvalue: UBVALUEATT ATTRIBUTETEXT QUOTE
{
};

otherconoptionend: GREATERTHAN CONEND | ENDOFELEMENT;


solveroptions: | SOLVEROPTIONSSTART numberofsolveroptionsatt GREATERTHAN solveroptionlist SOLVEROPTIONSEND;

numberofsolveroptionsatt: NUMBEROFSOLVEROPTIONSATT ATTRIBUTETEXT QUOTE
{
};

solveroptionlist: | solveroptionlist solveroption;

solveroption: SOLVEROPTIONSTART solveroptionattlist solveroptionend;

solveroptionattlist: | solveroptionattlist solveroptionatt;

solveroptionatt: 
     solveroptionname
   | solveroptionvalue
   | solveroptionsolver
   | solveroptioncategory
   | solveroptiontype
   | solveroptiondescription;

solveroptionname: NAMEATT ATTRIBUTETEXT QUOTE
{
};

solveroptionvalue: VALUEATT ATTRIBUTETEXT QUOTE
{
};

solveroptionsolver: SOLVERATT ATTRIBUTETEXT QUOTE
{
};

solveroptioncategory: CATEGORYATT ATTRIBUTETEXT QUOTE
{
};

solveroptiontype: TYPEATT ATTRIBUTETEXT QUOTE
{
};

solveroptiondescription: DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};


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

