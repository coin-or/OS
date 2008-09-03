/** @file parseosol.y
 * 
 * @author  Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.1, 10/07/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin,
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
this fails on in Mac OS X
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




%token QUOTE GREATERTHAN ENDOFELEMENT 
%token OSOLSTART OSOLATTRIBUTETEXT OSOLEND


%token LOCATIONTYPEATT TRANSPORTTYPEATT;
%token NUMBEROFJOBIDSATT NUMBEROFPATHSATT NUMBEROFPROCESSESATT;
%token NUMBEROFVARIABLESATT NUMBEROFOBJECTIVESATT NUMBEROFCONSTRAINTSATT NUMBEROFOTHEROPTIONSATT;
%token NUMBEROFOTHERVARIABLEOPTIONSATT NUMBEROFOTHEROBJECTIVEOPTIONSATT NUMBEROFOTHERCONSTRAINTOPTIONSATT;
%token NUMBEROFVARATT NUMBEROFOBJATT NUMBEROFCONATT;
%token NAMEATT IDXATT VALUEATT DESCRIPTIONATT LBVALUEATT UBVALUEATT;

%token GENERALSTART GENERALEND SYSTEMSTART SYSTEMEND SERVICESTART SERVICEEND;
%token JOBSTART JOBEND OPTIMIZATIONSTART OPTIMIZATIONEND OTHERSTART OTHEREND;
%token SERVICEURISTART SERVICEURIEND SERVICENAMESTART SERVICENAMEEND CONTACTSTART CONTACTEND; 
%token INSTANCENAMESTART INSTANCENAMEEND INSTANCELOCATIONSTART INSTANCELOCATIONEND;
%token JOBIDSTART JOBIDEND LICENSESTART LICENSEEND USERNAMESTART USERNAMEEND PASSWORDSTART PASSWORDEND;
%token MINDISKSPACESTART MINDISKSPACEEND MINMEMORYSIZESTART MINMEMORYSIZEEND MINCPUSPEEDSTART MINCPUSPEEDEND;
%token SERVICETYPESTART SERVICETYPEEND;
%token MAXTIMESTART MAXTIMEEND SCHEDULEDSTARTTIMESTART SCHEDULEDSTARTTIMEEND; 
%token DEPENDENCIESSTART DEPENDENCIESEND;
%token REQDIRSTART REQDIREND PATHSTART PATHEND;
%token MAKEDIRSTART MAKEDIREND MAKEFILESTART MAKEFILEEND DELDIRSTART DELDIREND DELFILESTART DELFILEEND;
%token  INPUTCOPYFROMSTART  INPUTCOPYFROMEND  INPUTCOPYTOSTART  INPUTCOPYTOEND;
%token  INPUTMOVEFROMSTART  INPUTMOVEFROMEND  INPUTMOVETOSTART  INPUTMOVETOEND;
%token OUTPUTCOPYFROMSTART OUTPUTCOPYFROMEND OUTPUTCOPYTOSTART OUTPUTCOPYTOEND;
%token OUTPUTMOVEFROMSTART OUTPUTMOVEFROMEND OUTPUTMOVETOSTART OUTPUTMOVETOEND;
%token PROCESSESTOKILLSTART PROCESSESTOKILLEND PROCESSSTART PROCESSEND;
%token OPTIMIZATIONVARIABLESSTART OPTIMIZATIONVARIABLESEND INITIALVARIABLESSTART INITIALVARIABLESEND;
%token INITIALVARSTART INITIALVAREND;
%token OPTIMIZATIONOBJECTIVESSTART OPTIMIZATIONOBJECTIVESEND INITIALOBJVALUESSTART INITIALOBJVALUESEND;
%token OPTIMIZATIONINITIALOBJSTART OPTIMIZATIONINITIALOBJEND INITIALOBJBOUNDSSTART INITIALOBJBOUNDSEND;
%token OPTIMIZATIONCONSTRAINTSSTART OPTIMIZATIONCONSTRAINTSEND INITIALCONSTRAINTSSTART INITIALCONSTRAINTSEND;
%token INITIALCONSTART INITIALCONEND INITIALDUALSSTART INITIALDUALSEND;

%token DUMMY

%%


osoldoc: osolstart GREATERTHAN osolcontent OSOLEND
	| osolstart ENDOFELEMENT;

osolstart:	OSOLSTART   
	| OSOLSTART OSOLATTRIBUTETEXT ;

osolcontent: osolgeneral osolsystem osolservice osoljob osoloptimization osolother;

osolgeneral: 
	| GENERALSTART GREATERTHAN generalcontent GENERALEND
	| GENERALSTART ENDOFELEMENT;

generalcontent: | generalcontent generaloption;

generaloption: serviceURI | servicename | instancename | instancelocation | jobid
 | license | username | password | contact;


serviceURI : | emptyURI | nonemptyURI;

emptyURI: SERVICEURISTART ENDOFELEMENT
	|   SERVICEURISTART GREATERTHAN SERVICEURIEND
{
};

nonemptyURI: SERVICEURISTART GREATERTHAN ELEMENTTEXT SERVICEURIEND
{
};


servicename : | emptyservicename | nonemptyservicename;

emptyservicename: SERVICENAMESTART ENDOFELEMENT
	|   SERVICENAMESTART GREATERTHAN SERVICENAMEEND
{
};

nonemptyservicename: SERVICENAMESTART GREATERTHAN ELEMENTTEXT SERVICENAMEEND
{
};


instancename : | emptyinstancename | nonemptyinstancename;

emptyinstancename: INSTANCENAMESTART ENDOFELEMENT
	|   INSTANCENAMESTART GREATERTHAN INSTANCENAMEEND
{
};

nonemptyinstancename: INSTANCENAMESTART GREATERTHAN ELEMENTTEXT INSTANCENAMEEND
{
};


instancelocation : | emptylocation | nonemptylocation;

emptylocation: INSTANCELOCATIONSTART ENDOFELEMENT
	|   INSTANCELOCATIONSTART locationtypeatt GREATERTHAN INSTANCELOCATIONEND
{
};

nonemptylocation: INSTANCELOCATIONSTART locationtypeatt GREATERTHAN ELEMENTTEXT INSTANCELOCATIONEND
{
};

locationtypeatt: | LOCATIONTYPEATT ATTRIBUTETEXT QUOTE
{
};


jobid : | emptyjobid | nonemptyjobid;

emptyjobid: JOBIDSTART ENDOFELEMENT
	|   JOBIDSTART GREATERTHAN JOBIDEND
{
};

nonemptyjobid: JOBIDSTART GREATERTHAN ELEMENTTEXT JOBIDEND
{
};


license : | emptylicense | nonemptylicense;

emptylicense: LICENSESTART ENDOFELEMENT
	|   LICENSESTART GREATERTHAN LICENSEEND
{
};

nonemptylicense: LICENSESTART GREATERTHAN ELEMENTTEXT LICENSEEND
{
};


username : | emptyusername | nonemptyusername;

emptyusername: USERNAMESTART ENDOFELEMENT
	|   USERNAMESTART GREATERTHAN USERNAMEEND
{
};

nonemptyusername: USERNAMESTART GREATERTHAN ELEMENTTEXT USERNAMEEND
{
};


password : | emptypassword | nonemptypassword;

emptypassword: PASSWORDSTART ENDOFELEMENT
	|   PASSWORDSTART GREATERTHAN PASSWORDEND
{
};

nonemptypassword: PASSWORDSTART GREATERTHAN ELEMENTTEXT PASSWORDEND
{
};

contact: | emptycontact | nonemptycontact;

emptycontact: CONTACTSTART ENDOFELEMENT
	|   CONTACTSTART transporttypeatt GREATERTHAN CONTACTEND
{
};

nonemptycontact: CONTACTSTART transporttypeatt GREATERTHAN ELEMENTTEXT CONTACTEND
{
};

transporttypeatt: | TRANSPORTTYPEATT ATTRIBUTETEXT QUOTE
{
};


osolsystem: 
	| SYSTEMSTART GREATERTHAN systemcontent SYSTEMEND
	| SYSTEMSTART ENDOFELEMENT;

systemcontent: | systemcontent systemoption;

systemoption: mindiskspace | minmemorysize | mincpuspeed;

mindiskspace: | emptymindiskspace | nonemptymindiskspace;

emptymindiskspace: MINDISKSPACESTART ENDOFELEMENT
	|   MINDISKSPACESTART GREATERTHAN MINDISKSPACEEND
{
};

nonemptymindiskspace: MINDISKSPACESTART GREATERTHAN ELEMENTTEXT MINDISKSPACEEND
{
};


minmemorysize: | emptyminmemorysize | nonemptyminmemorysize;

emptyminmemorysize: MINMEMORYSIZESTART ENDOFELEMENT
	|   MINMEMORYSIZESTART GREATERTHAN MINMEMORYSIZEEND
{
};

nonemptyminmemorysize: MINMEMORYSIZESTART GREATERTHAN ELEMENTTEXT MINMEMORYSIZEEND
{
};


mincpuspeed: | emptymincpuspeed | nonemptymincpuspeed;

emptymincpuspeed: MINCPUSPEEDSTART ENDOFELEMENT
	|   MINCPUSPEEDSTART GREATERTHAN MINCPUSPEEDEND
{
};

nonemptymincpuspeed: MINCPUSPEEDSTART GREATERTHAN ELEMENTTEXT MINCPUSPEEDEND
{
};


osolservice: 
	| SERVICESTART GREATERTHAN servicecontent SERVICEEND
	| SERVICESTART ENDOFELEMENT;

servicecontent: | servicecontent serviceoption;

serviceoption: servicetype;

servicetype: | emptyservicetype | nonemptyservicetype;

emptyservicetype: SERVICETYPESTART ENDOFELEMENT
	|   SERVICETYPESTART GREATERTHAN SERVICETYPEEND
{
};

nonemptyservicetype: SERVICETYPESTART GREATERTHAN ELEMENTTEXT SERVICETYPEEND
{
};


osoljob: 
	| JOBSTART GREATERTHAN jobcontent JOBEND
	| JOBSTART ENDOFELEMENT;

jobcontent:;


osoloptimization: 
	| OPTIMIZATIONSTART GREATERTHAN optimizationcontent OPTIMIZATIONEND
	| OPTIMIZATIONSTART ENDOFELEMENT;

optimizationcontent:;


osolother: 
	| OTHERSTART GREATERTHAN othercontent OTHEREND
	| OTHERSTART ENDOFELEMENT;

othercontent:;







quote: xmlWhiteSpace QUOTE;

xmlWhiteSpaceChar: ' ' 
				| '\t'
				| '\r'
				| '\n' ;
				
xmlWhiteSpace: 
			| xmlWhiteSpace xmlWhiteSpaceChar ;
			

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

