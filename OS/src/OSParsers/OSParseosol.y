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

osolgeneral: 
	| GENERALSTART GREATERTHAN generalcontent GENERALEND
	| GENERALSTART ENDOFELEMENT;

generalcontent: | generalcontent generaloption;

generaloption: serviceURI | servicename | instancename | instancelocation | jobid
 | solvertoinvoke | license | username | password | contact | othergeneraloptions;


serviceURI: emptyURI | nonemptyURI;

emptyURI: SERVICEURISTART ENDOFELEMENT
	|   SERVICEURISTART GREATERTHAN SERVICEURIEND
{
};

nonemptyURI: SERVICEURISTART GREATERTHAN ELEMENTTEXT SERVICEURIEND
{
};


servicename: emptyservicename | nonemptyservicename;

emptyservicename: SERVICENAMESTART ENDOFELEMENT
	|   SERVICENAMESTART GREATERTHAN SERVICENAMEEND
{
};

nonemptyservicename: SERVICENAMESTART GREATERTHAN ELEMENTTEXT SERVICENAMEEND
{
};


instancename: emptyinstancename | nonemptyinstancename;

emptyinstancename: INSTANCENAMESTART ENDOFELEMENT
	|   INSTANCENAMESTART GREATERTHAN INSTANCENAMEEND
{
};

nonemptyinstancename: INSTANCENAMESTART GREATERTHAN ELEMENTTEXT INSTANCENAMEEND
{
};


instancelocation: emptylocation | nonemptylocation;

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


jobid: emptyjobid | nonemptyjobid;

emptyjobid: JOBIDSTART ENDOFELEMENT
	|   JOBIDSTART GREATERTHAN JOBIDEND
{
};

nonemptyjobid: JOBIDSTART GREATERTHAN ELEMENTTEXT JOBIDEND
{
};


solvertoinvoke: emptysolver | nonemptysolver;

emptysolver: SOLVERTOINVOKESTART ENDOFELEMENT
        |   SOLVERTOINVOKESTART GREATERTHAN SOLVERTOINVOKEEND
{
};

nonemptysolver: SOLVERTOINVOKESTART GREATERTHAN ELEMENTTEXT SOLVERTOINVOKEEND
{
};


license: emptylicense | nonemptylicense;

emptylicense: LICENSESTART ENDOFELEMENT
	|   LICENSESTART GREATERTHAN LICENSEEND
{
};

nonemptylicense: LICENSESTART GREATERTHAN ELEMENTTEXT LICENSEEND
{
};


username: emptyusername | nonemptyusername;

emptyusername: USERNAMESTART ENDOFELEMENT
	|   USERNAMESTART GREATERTHAN USERNAMEEND
{
};

nonemptyusername: USERNAMESTART GREATERTHAN ELEMENTTEXT USERNAMEEND
{
};


password: emptypassword | nonemptypassword;

emptypassword: PASSWORDSTART ENDOFELEMENT
	|   PASSWORDSTART GREATERTHAN PASSWORDEND
{
};

nonemptypassword: PASSWORDSTART GREATERTHAN ELEMENTTEXT PASSWORDEND
{
};

contact: emptycontact | nonemptycontact;

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


othergeneraloptions: OTHEROPTIONSSTART numberofothergeneraloptions GREATERTHAN othergeneraloptionslist OTHEROPTIONSEND;

numberofothergeneraloptions: NUMBEROFOTHEROPTIONSATT ATTRIBUTETEXT QUOTE
{
};

othergeneraloptionslist: | othergeneraloptionslist othergeneraloption;

othergeneraloption: OTHERSTART othergeneralattributes othergeneraloptionsend;

othergeneralattributes: | othergeneralattributes othergeneralattribute;

othergeneralattribute: generaloptionnameatt generaloptionvalueatt generaloptiondescriptionatt;

generaloptionnameatt: NAMEATT ATTRIBUTETEXT QUOTE
{
};

generaloptionvalueatt: | VALUEATT ATTRIBUTETEXT QUOTE
{
};

generaloptiondescriptionatt: | DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};

othergeneraloptionsend: ENDOFELEMENT | GREATERTHAN OTHEREND
{
};


osolsystem: 
	| SYSTEMSTART GREATERTHAN systemcontent SYSTEMEND
	| SYSTEMSTART ENDOFELEMENT;

systemcontent: | systemcontent systemoption;

systemoption: mindiskspace | minmemorysize | mincpuspeed | mincpunumber | othersystemoptions;

mindiskspace: MINDISKSPACESTART mindiskspaceunit GREATERTHAN DOUBLE MINDISKSPACEEND
{
};
mindiskspaceunit: | UNITATT ATTRIBUTETEXT QUOTE
{
};

minmemorysize: MINMEMORYSIZESTART minmemoryunit GREATERTHAN DOUBLE MINMEMORYSIZEEND
{
};

minmemoryunit: | UNITATT ATTRIBUTETEXT QUOTE
{
};

mincpuspeed: MINCPUSPEEDSTART mincpuspeedunit GREATERTHAN DOUBLE MINCPUSPEEDEND
{
};

mincpuspeedunit: | UNITATT ATTRIBUTETEXT QUOTE
{
};

mincpunumber: emptymincpunumber | nonemptymincpunumber;

emptymincpunumber: MINCPUNUMBERSTART ENDOFELEMENT
	|   MINCPUNUMBERSTART GREATERTHAN MINCPUNUMBEREND
{
};

nonemptymincpunumber: MINCPUNUMBERSTART GREATERTHAN DOUBLE MINCPUNUMBEREND
{
};

othersystemoptions: OTHEROPTIONSSTART numberofothersystemoptions GREATERTHAN othersystemoptionslist OTHEROPTIONSEND;

numberofothersystemoptions: NUMBEROFOTHEROPTIONSATT ATTRIBUTETEXT QUOTE
{
};

othersystemoptionslist: | othersystemoptionslist othersystemoption;

othersystemoption: OTHERSTART othersystemattributes othersystemoptionsend;

othersystemattributes: | othersystemattributes othersystemattribute;

othersystemattribute: systemoptionnameatt systemoptionvalueatt systemoptiondescriptionatt;

systemoptionnameatt: NAMEATT ATTRIBUTETEXT QUOTE
{
};

systemoptionvalueatt: | VALUEATT ATTRIBUTETEXT QUOTE
{
};

systemoptiondescriptionatt: | DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};

othersystemoptionsend: ENDOFELEMENT | GREATERTHAN OTHEREND
{
};


osolservice: 
	| SERVICESTART GREATERTHAN servicecontent SERVICEEND
	| SERVICESTART ENDOFELEMENT;

servicecontent: | servicecontent serviceoption;

serviceoption: servicetype | otherserviceoptions;

servicetype: emptyservicetype | nonemptyservicetype;

emptyservicetype: SERVICETYPESTART ENDOFELEMENT
	|   SERVICETYPESTART GREATERTHAN SERVICETYPEEND
{
};

nonemptyservicetype: SERVICETYPESTART GREATERTHAN ELEMENTTEXT SERVICETYPEEND
{
};


otherserviceoptions: OTHEROPTIONSSTART numberofotherserviceoptions GREATERTHAN otherserviceoptionslist OTHEROPTIONSEND;

numberofotherserviceoptions: NUMBEROFOTHEROPTIONSATT ATTRIBUTETEXT QUOTE
{
};

otherserviceoptionslist: | otherserviceoptionslist otherserviceoption;

otherserviceoption: OTHERSTART otherserviceattributes otherserviceoptionsend;

otherserviceattributes: | otherserviceattributes otherserviceattribute;

otherserviceattribute: serviceoptionnameatt serviceoptionvalueatt serviceoptiondescriptionatt;

serviceoptionnameatt: NAMEATT ATTRIBUTETEXT QUOTE
{
};

serviceoptionvalueatt: | VALUEATT ATTRIBUTETEXT QUOTE
{
};

serviceoptiondescriptionatt: | DESCRIPTIONATT ATTRIBUTETEXT QUOTE
{
};

otherserviceoptionsend: ENDOFELEMENT | GREATERTHAN OTHEREND
{
};


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

