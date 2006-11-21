package org.optimizationservices.osmodeler.parser.osml;
/* Generated By:JavaCC: Do not edit this line. OSmLPreParser.java */
//package org.optimizationservices.osmodeler.parser.osml;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Stack;
import java.util.Vector;
public class OSmLPreParser implements OSmLPreParserConstants {
        java.util.Vector tokenVector = new java.util.Vector();
        static boolean insideCon = false;
        static boolean insideUserF = false;
        static boolean numgt = false;
        static int testidx = -1;
        static String firstPart;
        public OSmLPreParser(){
        }
        static public void main(String[] args){
                String fileName = "./xml/markowitzmod2.xq";
                FileInputStream fis = null;
                OSmLPreParser parser;
        try{
            String sOSmL = null;
            File file = new File(fileName);
            if( file.exists() && file.canRead()){
                fis = new FileInputStream(file);
                byte theBytes[] = new byte[(int)file.length()];
                if( ((long)fis.read(theBytes, 0, (int) file.length())) == file.length()){
                        sOSmL = new String(theBytes );
                }
            }
            fis.close();
            OSmLPreParser.initOSmL( sOSmL);

        }
        catch(Exception e){
            e.printStackTrace();

        }
        }
        static public void initOSmL(String sOSmL){
                /* convert from string to InputStream */
                InputStream is = new ByteArrayInputStream( sOSmL.getBytes());
            OSmLPreParser parser = new OSmLPreParser(is);
            String newXQ = parser.preParse();
            System.out.println( newXQ );
        }
        public String preParse() {
                Vector tokenVector = new Vector();
                try {
                        tokenVector = this.gettokenVector();
                }
                catch (ParseException pe) {
                        pe.printStackTrace();
                }
                this.addTerms(tokenVector);
                String preparsedModel = "";
                for(int i = 0; i < tokenVector.size(); i++)
                {
                        preparsedModel = preparsedModel  +(String)tokenVector.get( i);
                }
                return preparsedModel;
        }
        private Vector addTerms(Vector tokenVector){
                /* take care of Saxon Quirk */
                String sFirstTok = (String)tokenVector.firstElement();
                if(sFirstTok.indexOf("return") > -1) tokenVector.add(0, "let $JMRKM127 := 1\n");
                Stack parenStack = new Stack();
                int position = -1;
                String sum = "<sum>";
                String ret = "return";
                int retposition = 0;
                String rightparen = ")";
                String leftparen = "(";
                String test="";
                while(++position < tokenVector.size()){
                        position = tokenVector.indexOf(sum, position);
                        if(position < 0){
                                break;
                        }
                        /* replace ( with { */
                        //System.out.println("Sum Position = " + position);
                        tokenVector.set(position + 1, "{" );
                        /* find the last parenthesis in the sum term */
                        /* push a ( to the stack */
                        parenStack.push(leftparen);
                        while(parenStack.size() > 0){
                                position += 1;
                                test = (String)tokenVector.get( position);
                                if(test.equals(leftparen)) parenStack.push( leftparen);
                                if(test.equals(rightparen)) parenStack.pop();
                                if(test.equals(ret)) retposition = position;
                        }
                        /* position should be the last ) in the sum function */
                        tokenVector.set(position, "</term>}</sum>" );
                        /* retposition should be the position of the last return */
                        tokenVector.insertElementAt(" <term>", retposition+1);
                }
                return tokenVector;
        }

/* We use the following method if we just want to get the tokens
and don't care about parsing */
  final public java.util.Vector gettokenVector() throws ParseException {
Token t;

    label_1:
    while (true) {
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case space:
      case slasht:
      case slashn:
      case slashr:
      case gt:
      case lt:
      case geq:
      case leq:
      case operator:
      case leftparen:
      case rightparen:
      case startCon:
      case endCon:
      case startConstraints:
      case endConstraints:
      case startvar:
      case endvar:
      case startvariables:
      case endvariables:
      case startUserfunction:
      case endUserfunction:
      case startUserfunctions:
      case endUserfunctions:
      case startmathProgram:
      case endmathProgram:
      case startobj:
      case endobj:
      case sum:
      case xpathNode:
      case atoken:
        ;
        break;
      default:
        jj_la1[0] = jj_gen;
        break label_1;
      }
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case atoken:
        t = jj_consume_token(atoken);
            tokenVector.add(t.image);
        break;
      case startCon:
        t = jj_consume_token(startCon);
insideCon = true;
numgt = false;
tokenVector.add(t.image);
        break;
      case endCon:
        t = jj_consume_token(endCon);
insideCon = false;
numgt = false;
tokenVector.add(t.image);
        break;
      case startUserfunction:
        t = jj_consume_token(startUserfunction);
insideUserF = true;
numgt = false;
tokenVector.add(t.image);
        break;
      case endUserfunction:
        t = jj_consume_token(endUserfunction);
insideUserF = false;
numgt = false;
tokenVector.add(t.image);
        break;
      case leftparen:
        t = jj_consume_token(leftparen);
               tokenVector.add(t.image);
        break;
      case rightparen:
        t = jj_consume_token(rightparen);
                tokenVector.add(t.image);
        break;
      case gt:
        t = jj_consume_token(gt);
/* we are inside the token <con> but there could be attributes
so we will still have a > token we don't want to count */
if(numgt  & (insideCon || insideUserF )){
tokenVector.add("&gt;");
}
else{
tokenVector.add(t.image);
numgt = true;
}
        break;
      case geq:
        t = jj_consume_token(geq);
if(insideCon || insideUserF){
tokenVector.add("&gt;=");
}
else{
tokenVector.add(t.image);
}
        break;
      case lt:
        t = jj_consume_token(lt);
if(insideCon || insideUserF){
tokenVector.add("&lt;");
}
else{
tokenVector.add(t.image);
}
        break;
      case leq:
        t = jj_consume_token(leq);
if(insideCon || insideUserF){
tokenVector.add("&lt;=");
}
else{
tokenVector.add(t.image);
}
        break;
      case xpathNode:
        t = jj_consume_token(xpathNode);
System.out.println(t.image);
                        int position = -1;
                        int endofXPath = 0;
                Stack parenStack = new Stack();
                        String rightparen = ")";
                        String leftparen = "(";
                        while(++position < t.image.length()){
                                position = t.image.indexOf(leftparen, position);
                                if(position < 0){
                                        break;
                                }
                                parenStack.push(leftparen);
                                System.out.println("position =  " + position);
                        }
                        position = 0;
                        while(parenStack.size() > 0){
                                position = t.image.indexOf(rightparen, position);
                                endofXPath = position;
                                if(position < 0){
                                        break;
                                }
                                ++position;
                                parenStack.pop();
                                System.out.println("position =  " + position);
                        }
                        System.out.println("size =  " + parenStack.size() );
                        /* Now break up the string */
                        String sXPath = t.image.substring(0, endofXPath);
                        /* replace the first ( it is in position 5 */
                        sXPath = sXPath.replaceFirst("[(]", ":");
                        sXPath = sXPath + " ";
                        /* now get rid of the comma  */
                        sXPath = sXPath.replaceFirst("[,]", ":");
                        System.out.println("sXPath =  " + sXPath);


/* replace all ( and ) before xPathIndex*/
testidx = sXPath.indexOf("(xPathIndex:");
if (testidx > -1){
        firstPart = sXPath.substring(0, testidx);
        firstPart = firstPart.replaceAll("[(]", "leftParen");
        firstPart = firstPart.replaceAll("[)]", "rightParen");
        String secondPart =  sXPath.substring(testidx );
        System.out.println("First Part = " +  firstPart);
        System.out.println("Second Part = " + secondPart);
        tokenVector.add(firstPart + secondPart);
}
else{
        tokenVector.add( sXPath);
}
        if(t.image.length() > endofXPath + 1){
                char[] textArray = t.image.substring(endofXPath + 1, t.image.length()).toCharArray();
                for(int i = 0; i < textArray.length; i++){
                        tokenVector.add( String.valueOf( textArray[i] ));
                }
        }
        break;
      case startConstraints:
        t = jj_consume_token(startConstraints);
                      tokenVector.add(t.image);
        break;
      case endConstraints:
        t = jj_consume_token(endConstraints);
                    tokenVector.add(t.image);
        break;
      case startUserfunctions:
        t = jj_consume_token(startUserfunctions);
                        tokenVector.add(t.image);
        break;
      case endUserfunctions:
        t = jj_consume_token(endUserfunctions);
                      tokenVector.add(t.image);
        break;
      case sum:
        t = jj_consume_token(sum);
         tokenVector.add("<sum>");
        break;
      case startmathProgram:
        t = jj_consume_token(startmathProgram);
                      tokenVector.add("<mathProgram ");
        break;
      case endmathProgram:
        t = jj_consume_token(endmathProgram);
                    tokenVector.add("</mathProgram>");
        break;
      case startobj:
        t = jj_consume_token(startobj);
              tokenVector.add("<obj>");
        break;
      case endobj:
        t = jj_consume_token(endobj);
            tokenVector.add("</obj>");
        break;
      case startvar:
        t = jj_consume_token(startvar);
              tokenVector.add("<var>");
        break;
      case endvar:
        t = jj_consume_token(endvar);
            tokenVector.add("</var>");
        break;
      case startvariables:
        t = jj_consume_token(startvariables);
                    tokenVector.add("<variables>");
        break;
      case endvariables:
        t = jj_consume_token(endvariables);
                  tokenVector.add("</variables>");
        break;
      case operator:
        t = jj_consume_token(operator);
              tokenVector.add(t.image);
        break;
      case space:
        t = jj_consume_token(space);
           tokenVector.add(t.image);
        break;
      case slasht:
        t = jj_consume_token(slasht);
            tokenVector.add(t.image);
        break;
      case slashn:
        t = jj_consume_token(slashn);
            tokenVector.add(t.image);
        break;
      case slashr:
        t = jj_consume_token(slashr);
            tokenVector.add(t.image);
        break;
      default:
        jj_la1[1] = jj_gen;
        jj_consume_token(-1);
        throw new ParseException();
      }
    }
    jj_consume_token(0);
  {if (true) return tokenVector;}
    throw new Error("Missing return statement in function");
  }

  public OSmLPreParserTokenManager token_source;
  SimpleCharStream jj_input_stream;
  public Token token, jj_nt;
  private int jj_ntk;
  private int jj_gen;
  final private int[] jj_la1 = new int[2];
  static private int[] jj_la1_0;
  static {
      jj_la1_0();
   }
   private static void jj_la1_0() {
      jj_la1_0 = new int[] {0x7ffffffe,0x7ffffffe,};
   }

  public OSmLPreParser(java.io.InputStream stream) {
    jj_input_stream = new SimpleCharStream(stream, 1, 1);
    token_source = new OSmLPreParserTokenManager(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 2; i++) jj_la1[i] = -1;
  }

  public void ReInit(java.io.InputStream stream) {
    jj_input_stream.ReInit(stream, 1, 1);
    token_source.ReInit(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 2; i++) jj_la1[i] = -1;
  }

  public OSmLPreParser(java.io.Reader stream) {
    jj_input_stream = new SimpleCharStream(stream, 1, 1);
    token_source = new OSmLPreParserTokenManager(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 2; i++) jj_la1[i] = -1;
  }

  public void ReInit(java.io.Reader stream) {
    jj_input_stream.ReInit(stream, 1, 1);
    token_source.ReInit(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 2; i++) jj_la1[i] = -1;
  }

  public OSmLPreParser(OSmLPreParserTokenManager tm) {
    token_source = tm;
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 2; i++) jj_la1[i] = -1;
  }

  public void ReInit(OSmLPreParserTokenManager tm) {
    token_source = tm;
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 2; i++) jj_la1[i] = -1;
  }

  final private Token jj_consume_token(int kind) throws ParseException {
    Token oldToken;
    if ((oldToken = token).next != null) token = token.next;
    else token = token.next = token_source.getNextToken();
    jj_ntk = -1;
    if (token.kind == kind) {
      jj_gen++;
      return token;
    }
    token = oldToken;
    jj_kind = kind;
    throw generateParseException();
  }

  final public Token getNextToken() {
    if (token.next != null) token = token.next;
    else token = token.next = token_source.getNextToken();
    jj_ntk = -1;
    jj_gen++;
    return token;
  }

  final public Token getToken(int index) {
    Token t = token;
    for (int i = 0; i < index; i++) {
      if (t.next != null) t = t.next;
      else t = t.next = token_source.getNextToken();
    }
    return t;
  }

  final private int jj_ntk() {
    if ((jj_nt=token.next) == null)
      return (jj_ntk = (token.next=token_source.getNextToken()).kind);
    else
      return (jj_ntk = jj_nt.kind);
  }

  private java.util.Vector jj_expentries = new java.util.Vector();
  private int[] jj_expentry;
  private int jj_kind = -1;

  public ParseException generateParseException() {
    jj_expentries.removeAllElements();
    boolean[] la1tokens = new boolean[31];
    for (int i = 0; i < 31; i++) {
      la1tokens[i] = false;
    }
    if (jj_kind >= 0) {
      la1tokens[jj_kind] = true;
      jj_kind = -1;
    }
    for (int i = 0; i < 2; i++) {
      if (jj_la1[i] == jj_gen) {
        for (int j = 0; j < 32; j++) {
          if ((jj_la1_0[i] & (1<<j)) != 0) {
            la1tokens[j] = true;
          }
        }
      }
    }
    for (int i = 0; i < 31; i++) {
      if (la1tokens[i]) {
        jj_expentry = new int[1];
        jj_expentry[0] = i;
        jj_expentries.addElement(jj_expentry);
      }
    }
    int[][] exptokseq = new int[jj_expentries.size()][];
    for (int i = 0; i < jj_expentries.size(); i++) {
      exptokseq[i] = (int[])jj_expentries.elementAt(i);
    }
    return new ParseException(token, exptokseq, tokenImage);
  }

  final public void enable_tracing() {
  }

  final public void disable_tracing() {
  }

}
