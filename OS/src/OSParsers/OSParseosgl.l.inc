 /* include file OSParseosgl.l.inc

 /* These elements are part of the OSgL schema and are used in both OSoL and OSrL parsers */
{xmlwhitespace}*\<matrix {YY_PRINT;  return(MATRIXSTART);}
{xmlwhitespace}*\<\/matrix{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXEND);}
{xmlwhitespace}*\<baseMatrix {YY_PRINT;  return(BASEMATRIXSTART);}
{xmlwhitespace}*\<\/baseMatrix{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(BASEMATRIXEND);}
{xmlwhitespace}*\<blocks {YY_PRINT;  return(BLOCKSSTART);}
{xmlwhitespace}*\<\/blocks{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(BLOCKSEND);}
{xmlwhitespace}*\<block {YY_PRINT;  return(BLOCKSTART);}
{xmlwhitespace}*\<\/block{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(BLOCKEND);}
{xmlwhitespace}*\<elements {YY_PRINT;  return(ELEMENTSSTART);}
{xmlwhitespace}*\<\/elements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ELEMENTSEND);}
{xmlwhitespace}*\<constantElements {YY_PRINT;  return(CONSTANTELEMENTSSTART);}
{xmlwhitespace}*\<\/constantElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CONSTANTELEMENTSEND);}
{xmlwhitespace}*\<varReferenceElements {YY_PRINT;  return(VARREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/varReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VARREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<linearElements {YY_PRINT;  return(LINEARELEMENTSSTART);}
{xmlwhitespace}*\<\/linearElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(LINEARELEMENTSEND);}
{xmlwhitespace}*\<generalElements {YY_PRINT;  return(GENERALELEMENTSSTART);}
{xmlwhitespace}*\<\/generalElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(GENERALELEMENTSEND);}
{xmlwhitespace}*\<start {YY_PRINT;  return(STARTVECTORSTART);}
{xmlwhitespace}*\<\/start{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(STARTVECTOREND);}
{xmlwhitespace}*\<nonzeros {YY_PRINT;  return(NONZEROSSTART);}
{xmlwhitespace}*\<\/nonzeros{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(NONZEROSEND);}
{xmlwhitespace}*\<indexes {YY_PRINT;  return(INDEXESSTART);}
{xmlwhitespace}*\<\/indexes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INDEXESEND);}
{xmlwhitespace}*\<nonzeros {YY_PRINT;  return(VALUESSTART);}
{xmlwhitespace}*\<\/nonzeros{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VALUESEND);}

 /* The <item> element and the children of the file header are treated specially because they may legitimately contain special characters */

{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}*\<\/item{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(ITEMEMPTY);}
{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(ITEMSTART);}
{xmlwhitespace}*\<\/item{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(ITEMEND);}
{xmlwhitespace}*\<item{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(ITEMSTARTANDEND);}

{xmlwhitespace}*\<name{xmlwhitespace}*\>{xmlwhitespace}*\<\/name{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILENAMEEMPTY);}
{xmlwhitespace}*\<name{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILENAMESTART);}
{xmlwhitespace}*\<\/name{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILENAMEEND);}
{xmlwhitespace}*\<name{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILENAMESTARTANDEND);}

{xmlwhitespace}*\<source{xmlwhitespace}*\>{xmlwhitespace}*\<\/source{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILESOURCEEMPTY);}
{xmlwhitespace}*\<source{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILESOURCESTART);}
{xmlwhitespace}*\<\/source{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILESOURCEEND);}
{xmlwhitespace}*\<source{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILESOURCESTARTANDEND);}

{xmlwhitespace}*\<description{xmlwhitespace}*\>{xmlwhitespace}*\<\/description{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILEDESCRIPTIONEMPTY);}
{xmlwhitespace}*\<description{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILEDESCRIPTIONSTART);}
{xmlwhitespace}*\<\/description{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILEDESCRIPTIONEND);}
{xmlwhitespace}*\<description{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILEDESCRIPTIONSTARTANDEND);}

{xmlwhitespace}*\<fileCreator{xmlwhitespace}*\>{xmlwhitespace}*\<\/fileCreator{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILECREATOREMPTY);}
{xmlwhitespace}*\<fileCreator{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILECREATORSTART);}
{xmlwhitespace}*\<\/fileCreator{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILECREATOREND);}
{xmlwhitespace}*\<fileCreator{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILECREATORSTARTANDEND);}

{xmlwhitespace}*\<licence{xmlwhitespace}*\>{xmlwhitespace}*\<\/licence{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILELICENCEEMPTY);}
{xmlwhitespace}*\<licence{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILELICENCESTART);}
{xmlwhitespace}*\<\/licence{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILELICENCEEND);}
{xmlwhitespace}*\<licence{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILELICENCESTARTANDEND);}


