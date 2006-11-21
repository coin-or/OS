package org.optimizationservices.osmodeler.parser.osml;
/* Generated By:JavaCC: Do not edit this line. OSmLPreParserTokenManager.java */
//package org.optimizationservices.osmodeler.parser.osml;

public class OSmLPreParserTokenManager implements OSmLPreParserConstants
{
  public  java.io.PrintStream debugStream = System.out;
  public  void setDebugStream(java.io.PrintStream ds) { debugStream = ds; }
private final int jjStopStringLiteralDfa_0(int pos, long active0)
{
   switch (pos)
   {
      case 0:
         if ((active0 & 0x10000000L) != 0L)
         {
            jjmatchedKind = 30;
            return 10;
         }
         return -1;
      case 1:
         if ((active0 & 0x10000000L) != 0L)
         {
            jjmatchedKind = 30;
            jjmatchedPos = 1;
            return 10;
         }
         return -1;
      case 2:
         if ((active0 & 0x10000000L) != 0L)
            return 10;
         return -1;
      default :
         return -1;
   }
}
private final int jjStartNfa_0(int pos, long active0)
{
   return jjMoveNfa_0(jjStopStringLiteralDfa_0(pos, active0), pos + 1);
}
private final int jjStopAtPos(int pos, int kind)
{
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   return pos + 1;
}
private final int jjStartNfaWithStates_0(int pos, int kind, int state)
{
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) { return pos + 1; }
   return jjMoveNfa_0(state, pos + 1);
}
private final int jjMoveStringLiteralDfa0_0()
{
   switch(curChar)
   {
      case 9:
         return jjStopAtPos(0, 2);
      case 10:
         return jjStopAtPos(0, 3);
      case 13:
         return jjStopAtPos(0, 4);
      case 32:
         return jjStopAtPos(0, 1);
      case 40:
         return jjStopAtPos(0, 10);
      case 41:
         return jjStopAtPos(0, 11);
      case 60:
         jjmatchedKind = 6;
         return jjMoveStringLiteralDfa1_0(0xffff100L);
      case 62:
         jjmatchedKind = 5;
         return jjMoveStringLiteralDfa1_0(0x80L);
      case 83:
         return jjMoveStringLiteralDfa1_0(0x10000000L);
      default :
         return jjMoveNfa_0(0, 0);
   }
}
private final int jjMoveStringLiteralDfa1_0(long active0)
{
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(0, active0);
      return 1;
   }
   switch(curChar)
   {
      case 47:
         return jjMoveStringLiteralDfa2_0(active0, 0xaaaa000L);
      case 61:
         if ((active0 & 0x80L) != 0L)
            return jjStopAtPos(1, 7);
         else if ((active0 & 0x100L) != 0L)
            return jjStopAtPos(1, 8);
         break;
      case 85:
         return jjMoveStringLiteralDfa2_0(active0, 0x10000000L);
      case 99:
         return jjMoveStringLiteralDfa2_0(active0, 0x5000L);
      case 109:
         return jjMoveStringLiteralDfa2_0(active0, 0x1000000L);
      case 111:
         return jjMoveStringLiteralDfa2_0(active0, 0x4000000L);
      case 117:
         return jjMoveStringLiteralDfa2_0(active0, 0x500000L);
      case 118:
         return jjMoveStringLiteralDfa2_0(active0, 0x50000L);
      default :
         break;
   }
   return jjStartNfa_0(0, active0);
}
private final int jjMoveStringLiteralDfa2_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(0, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(1, active0);
      return 2;
   }
   switch(curChar)
   {
      case 77:
         if ((active0 & 0x10000000L) != 0L)
            return jjStartNfaWithStates_0(2, 28, 10);
         break;
      case 97:
         return jjMoveStringLiteralDfa3_0(active0, 0x1050000L);
      case 98:
         return jjMoveStringLiteralDfa3_0(active0, 0x4000000L);
      case 99:
         return jjMoveStringLiteralDfa3_0(active0, 0xa000L);
      case 109:
         return jjMoveStringLiteralDfa3_0(active0, 0x2000000L);
      case 111:
         return jjMoveStringLiteralDfa3_0(active0, 0x8005000L);
      case 115:
         return jjMoveStringLiteralDfa3_0(active0, 0x500000L);
      case 117:
         return jjMoveStringLiteralDfa3_0(active0, 0xa00000L);
      case 118:
         return jjMoveStringLiteralDfa3_0(active0, 0xa0000L);
      default :
         break;
   }
   return jjStartNfa_0(1, active0);
}
private final int jjMoveStringLiteralDfa3_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(1, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(2, active0);
      return 3;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa4_0(active0, 0x20a0000L);
      case 98:
         return jjMoveStringLiteralDfa4_0(active0, 0x8000000L);
      case 101:
         return jjMoveStringLiteralDfa4_0(active0, 0x500000L);
      case 106:
         return jjMoveStringLiteralDfa4_0(active0, 0x4000000L);
      case 110:
         if ((active0 & 0x1000L) != 0L)
         {
            jjmatchedKind = 12;
            jjmatchedPos = 3;
         }
         return jjMoveStringLiteralDfa4_0(active0, 0x4000L);
      case 111:
         return jjMoveStringLiteralDfa4_0(active0, 0xa000L);
      case 114:
         return jjMoveStringLiteralDfa4_0(active0, 0x50000L);
      case 115:
         return jjMoveStringLiteralDfa4_0(active0, 0xa00000L);
      case 116:
         return jjMoveStringLiteralDfa4_0(active0, 0x1000000L);
      default :
         break;
   }
   return jjStartNfa_0(2, active0);
}
private final int jjMoveStringLiteralDfa4_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(2, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(3, active0);
      return 4;
   }
   switch(curChar)
   {
      case 62:
         if ((active0 & 0x10000L) != 0L)
            return jjStopAtPos(4, 16);
         else if ((active0 & 0x4000000L) != 0L)
            return jjStopAtPos(4, 26);
         break;
      case 101:
         return jjMoveStringLiteralDfa5_0(active0, 0xa00000L);
      case 104:
         return jjMoveStringLiteralDfa5_0(active0, 0x1000000L);
      case 105:
         return jjMoveStringLiteralDfa5_0(active0, 0x40000L);
      case 106:
         return jjMoveStringLiteralDfa5_0(active0, 0x8000000L);
      case 110:
         return jjMoveStringLiteralDfa5_0(active0, 0xa000L);
      case 114:
         return jjMoveStringLiteralDfa5_0(active0, 0x5a0000L);
      case 115:
         return jjMoveStringLiteralDfa5_0(active0, 0x4000L);
      case 116:
         return jjMoveStringLiteralDfa5_0(active0, 0x2000000L);
      default :
         break;
   }
   return jjStartNfa_0(3, active0);
}
private final int jjMoveStringLiteralDfa5_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(3, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(4, active0);
      return 5;
   }
   switch(curChar)
   {
      case 62:
         if ((active0 & 0x2000L) != 0L)
            return jjStopAtPos(5, 13);
         else if ((active0 & 0x20000L) != 0L)
            return jjStopAtPos(5, 17);
         else if ((active0 & 0x8000000L) != 0L)
            return jjStopAtPos(5, 27);
         break;
      case 80:
         return jjMoveStringLiteralDfa6_0(active0, 0x1000000L);
      case 97:
         return jjMoveStringLiteralDfa6_0(active0, 0x40000L);
      case 102:
         return jjMoveStringLiteralDfa6_0(active0, 0x500000L);
      case 104:
         return jjMoveStringLiteralDfa6_0(active0, 0x2000000L);
      case 105:
         return jjMoveStringLiteralDfa6_0(active0, 0x80000L);
      case 114:
         return jjMoveStringLiteralDfa6_0(active0, 0xa00000L);
      case 115:
         return jjMoveStringLiteralDfa6_0(active0, 0x8000L);
      case 116:
         return jjMoveStringLiteralDfa6_0(active0, 0x4000L);
      default :
         break;
   }
   return jjStartNfa_0(4, active0);
}
private final int jjMoveStringLiteralDfa6_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(4, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(5, active0);
      return 6;
   }
   switch(curChar)
   {
      case 80:
         return jjMoveStringLiteralDfa7_0(active0, 0x2000000L);
      case 97:
         return jjMoveStringLiteralDfa7_0(active0, 0x80000L);
      case 98:
         return jjMoveStringLiteralDfa7_0(active0, 0x40000L);
      case 102:
         return jjMoveStringLiteralDfa7_0(active0, 0xa00000L);
      case 114:
         return jjMoveStringLiteralDfa7_0(active0, 0x1004000L);
      case 116:
         return jjMoveStringLiteralDfa7_0(active0, 0x8000L);
      case 117:
         return jjMoveStringLiteralDfa7_0(active0, 0x500000L);
      default :
         break;
   }
   return jjStartNfa_0(5, active0);
}
private final int jjMoveStringLiteralDfa7_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(5, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(6, active0);
      return 7;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa8_0(active0, 0x4000L);
      case 98:
         return jjMoveStringLiteralDfa8_0(active0, 0x80000L);
      case 108:
         return jjMoveStringLiteralDfa8_0(active0, 0x40000L);
      case 110:
         return jjMoveStringLiteralDfa8_0(active0, 0x500000L);
      case 111:
         return jjMoveStringLiteralDfa8_0(active0, 0x1000000L);
      case 114:
         return jjMoveStringLiteralDfa8_0(active0, 0x2008000L);
      case 117:
         return jjMoveStringLiteralDfa8_0(active0, 0xa00000L);
      default :
         break;
   }
   return jjStartNfa_0(6, active0);
}
private final int jjMoveStringLiteralDfa8_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(6, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(7, active0);
      return 8;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa9_0(active0, 0x8000L);
      case 99:
         return jjMoveStringLiteralDfa9_0(active0, 0x500000L);
      case 101:
         return jjMoveStringLiteralDfa9_0(active0, 0x40000L);
      case 103:
         return jjMoveStringLiteralDfa9_0(active0, 0x1000000L);
      case 105:
         return jjMoveStringLiteralDfa9_0(active0, 0x4000L);
      case 108:
         return jjMoveStringLiteralDfa9_0(active0, 0x80000L);
      case 110:
         return jjMoveStringLiteralDfa9_0(active0, 0xa00000L);
      case 111:
         return jjMoveStringLiteralDfa9_0(active0, 0x2000000L);
      default :
         break;
   }
   return jjStartNfa_0(7, active0);
}
private final int jjMoveStringLiteralDfa9_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(7, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(8, active0);
      return 9;
   }
   switch(curChar)
   {
      case 99:
         return jjMoveStringLiteralDfa10_0(active0, 0xa00000L);
      case 101:
         return jjMoveStringLiteralDfa10_0(active0, 0x80000L);
      case 103:
         return jjMoveStringLiteralDfa10_0(active0, 0x2000000L);
      case 105:
         return jjMoveStringLiteralDfa10_0(active0, 0x8000L);
      case 110:
         return jjMoveStringLiteralDfa10_0(active0, 0x4000L);
      case 114:
         return jjMoveStringLiteralDfa10_0(active0, 0x1000000L);
      case 115:
         return jjMoveStringLiteralDfa10_0(active0, 0x40000L);
      case 116:
         return jjMoveStringLiteralDfa10_0(active0, 0x500000L);
      default :
         break;
   }
   return jjStartNfa_0(8, active0);
}
private final int jjMoveStringLiteralDfa10_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(8, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(9, active0);
      return 10;
   }
   switch(curChar)
   {
      case 62:
         if ((active0 & 0x40000L) != 0L)
            return jjStopAtPos(10, 18);
         break;
      case 97:
         return jjMoveStringLiteralDfa11_0(active0, 0x1000000L);
      case 105:
         return jjMoveStringLiteralDfa11_0(active0, 0x500000L);
      case 110:
         return jjMoveStringLiteralDfa11_0(active0, 0x8000L);
      case 114:
         return jjMoveStringLiteralDfa11_0(active0, 0x2000000L);
      case 115:
         return jjMoveStringLiteralDfa11_0(active0, 0x80000L);
      case 116:
         return jjMoveStringLiteralDfa11_0(active0, 0xa04000L);
      default :
         break;
   }
   return jjStartNfa_0(9, active0);
}
private final int jjMoveStringLiteralDfa11_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(9, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(10, active0);
      return 11;
   }
   switch(curChar)
   {
      case 62:
         if ((active0 & 0x80000L) != 0L)
            return jjStopAtPos(11, 19);
         break;
      case 97:
         return jjMoveStringLiteralDfa12_0(active0, 0x2000000L);
      case 105:
         return jjMoveStringLiteralDfa12_0(active0, 0xa00000L);
      case 109:
         return jjMoveStringLiteralDfa12_0(active0, 0x1000000L);
      case 111:
         return jjMoveStringLiteralDfa12_0(active0, 0x500000L);
      case 115:
         return jjMoveStringLiteralDfa12_0(active0, 0x4000L);
      case 116:
         return jjMoveStringLiteralDfa12_0(active0, 0x8000L);
      default :
         break;
   }
   return jjStartNfa_0(10, active0);
}
private final int jjMoveStringLiteralDfa12_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(10, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(11, active0);
      return 12;
   }
   switch(curChar)
   {
      case 32:
         if ((active0 & 0x1000000L) != 0L)
            return jjStopAtPos(12, 24);
         break;
      case 62:
         if ((active0 & 0x4000L) != 0L)
            return jjStopAtPos(12, 14);
         break;
      case 109:
         return jjMoveStringLiteralDfa13_0(active0, 0x2000000L);
      case 110:
         if ((active0 & 0x100000L) != 0L)
         {
            jjmatchedKind = 20;
            jjmatchedPos = 12;
         }
         return jjMoveStringLiteralDfa13_0(active0, 0x400000L);
      case 111:
         return jjMoveStringLiteralDfa13_0(active0, 0xa00000L);
      case 115:
         return jjMoveStringLiteralDfa13_0(active0, 0x8000L);
      default :
         break;
   }
   return jjStartNfa_0(11, active0);
}
private final int jjMoveStringLiteralDfa13_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(11, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(12, active0);
      return 13;
   }
   switch(curChar)
   {
      case 62:
         if ((active0 & 0x8000L) != 0L)
            return jjStopAtPos(13, 15);
         else if ((active0 & 0x2000000L) != 0L)
            return jjStopAtPos(13, 25);
         break;
      case 110:
         return jjMoveStringLiteralDfa14_0(active0, 0xa00000L);
      case 115:
         return jjMoveStringLiteralDfa14_0(active0, 0x400000L);
      default :
         break;
   }
   return jjStartNfa_0(12, active0);
}
private final int jjMoveStringLiteralDfa14_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(12, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(13, active0);
      return 14;
   }
   switch(curChar)
   {
      case 62:
         if ((active0 & 0x200000L) != 0L)
            return jjStopAtPos(14, 21);
         else if ((active0 & 0x400000L) != 0L)
            return jjStopAtPos(14, 22);
         break;
      case 115:
         return jjMoveStringLiteralDfa15_0(active0, 0x800000L);
      default :
         break;
   }
   return jjStartNfa_0(13, active0);
}
private final int jjMoveStringLiteralDfa15_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(13, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(14, active0);
      return 15;
   }
   switch(curChar)
   {
      case 62:
         if ((active0 & 0x800000L) != 0L)
            return jjStopAtPos(15, 23);
         break;
      default :
         break;
   }
   return jjStartNfa_0(14, active0);
}
private final void jjCheckNAdd(int state)
{
   if (jjrounds[state] != jjround)
   {
      jjstateSet[jjnewStateCnt++] = state;
      jjrounds[state] = jjround;
   }
}
private final void jjAddStates(int start, int end)
{
   do {
      jjstateSet[jjnewStateCnt++] = jjnextStates[start];
   } while (start++ != end);
}
private final void jjCheckNAddTwoStates(int state1, int state2)
{
   jjCheckNAdd(state1);
   jjCheckNAdd(state2);
}
private final void jjCheckNAddStates(int start, int end)
{
   do {
      jjCheckNAdd(jjnextStates[start]);
   } while (start++ != end);
}
private final void jjCheckNAddStates(int start)
{
   jjCheckNAdd(jjnextStates[start]);
   jjCheckNAdd(jjnextStates[start + 1]);
}
private final int jjMoveNfa_0(int startState, int curPos)
{
   int[] nextStates;
   int startsAt = 0;
   jjnewStateCnt = 11;
   int i = 1;
   jjstateSet[0] = startState;
   int j, kind = 0x7fffffff;
   for (;;)
   {
      if (++jjround == 0x7fffffff)
         ReInitRounds();
      if (curChar < 64)
      {
         long l = 1L << curChar;
         MatchLoop: do
         {
            switch(jjstateSet[--i])
            {
               case 0:
                  if ((0x2fff501e00000000L & l) != 0L)
                  {
                     if (kind > 30)
                        kind = 30;
                     jjCheckNAdd(10);
                  }
                  else if ((0xac0000000000L & l) != 0L)
                  {
                     if (kind > 9)
                        kind = 9;
                  }
                  break;
               case 1:
                  if (curChar == 40)
                     jjCheckNAdd(2);
                  break;
               case 2:
                  if ((0x7fffc05000000000L & l) != 0L)
                     jjCheckNAddTwoStates(2, 3);
                  break;
               case 3:
                  if (curChar == 44)
                     jjCheckNAdd(4);
                  break;
               case 4:
                  if ((0x7fffc7d000000000L & l) == 0L)
                     break;
                  if (kind > 29)
                     kind = 29;
                  jjCheckNAdd(4);
                  break;
               case 10:
                  if ((0x2fff501e00000000L & l) == 0L)
                     break;
                  if (kind > 30)
                     kind = 30;
                  jjCheckNAdd(10);
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else if (curChar < 128)
      {
         long l = 1L << (curChar & 077);
         MatchLoop: do
         {
            switch(jjstateSet[--i])
            {
               case 0:
                  if ((0x2ffffffeafffffffL & l) != 0L)
                  {
                     if (kind > 30)
                        kind = 30;
                     jjCheckNAdd(10);
                  }
                  else if (curChar == 94)
                  {
                     if (kind > 9)
                        kind = 9;
                  }
                  if (curChar == 120)
                     jjstateSet[jjnewStateCnt++] = 8;
                  break;
               case 2:
                  if ((0x7fffffe2fffffffL & l) != 0L)
                     jjAddStates(0, 1);
                  break;
               case 4:
                  if ((0x2ffffffe2fffffffL & l) == 0L)
                     break;
                  if (kind > 29)
                     kind = 29;
                  jjstateSet[jjnewStateCnt++] = 4;
                  break;
               case 5:
                  if (curChar == 104)
                     jjstateSet[jjnewStateCnt++] = 1;
                  break;
               case 6:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 5;
                  break;
               case 7:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 6;
                  break;
               case 8:
                  if (curChar == 80)
                     jjstateSet[jjnewStateCnt++] = 7;
                  break;
               case 9:
                  if (curChar == 120)
                     jjstateSet[jjnewStateCnt++] = 8;
                  break;
               case 10:
                  if ((0x2ffffffeafffffffL & l) == 0L)
                     break;
                  if (kind > 30)
                     kind = 30;
                  jjCheckNAdd(10);
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else
      {
         int i2 = (curChar & 0xff) >> 6;
         long l2 = 1L << (curChar & 077);
         MatchLoop: do
         {
            switch(jjstateSet[--i])
            {
               default : break;
            }
         } while(i != startsAt);
      }
      if (kind != 0x7fffffff)
      {
         jjmatchedKind = kind;
         jjmatchedPos = curPos;
         kind = 0x7fffffff;
      }
      ++curPos;
      if ((i = jjnewStateCnt) == (startsAt = 11 - (jjnewStateCnt = startsAt)))
         return curPos;
      try { curChar = input_stream.readChar(); }
      catch(java.io.IOException e) { return curPos; }
   }
}
static final int[] jjnextStates = {
   2, 3, 
};
public static final String[] jjstrLiteralImages = {
"", "\40", "\11", "\12", "\15", "\76", "\74", "\76\75", "\74\75", null, "\50", 
"\51", "\74\143\157\156", "\74\57\143\157\156\76", 
"\74\143\157\156\163\164\162\141\151\156\164\163\76", "\74\57\143\157\156\163\164\162\141\151\156\164\163\76", "\74\166\141\162\76", 
"\74\57\166\141\162\76", "\74\166\141\162\151\141\142\154\145\163\76", 
"\74\57\166\141\162\151\141\142\154\145\163\76", "\74\165\163\145\162\146\165\156\143\164\151\157\156", 
"\74\57\165\163\145\162\146\165\156\143\164\151\157\156\76", "\74\165\163\145\162\146\165\156\143\164\151\157\156\163\76", 
"\74\57\165\163\145\162\146\165\156\143\164\151\157\156\163\76", "\74\155\141\164\150\120\162\157\147\162\141\155\40", 
"\74\57\155\141\164\150\120\162\157\147\162\141\155\76", "\74\157\142\152\76", "\74\57\157\142\152\76", "\123\125\115", null, null, };
public static final String[] lexStateNames = {
   "DEFAULT", 
};
protected SimpleCharStream input_stream;
private final int[] jjrounds = new int[11];
private final int[] jjstateSet = new int[22];
protected char curChar;
public OSmLPreParserTokenManager(SimpleCharStream stream)
{
   if (SimpleCharStream.staticFlag)
      throw new Error("ERROR: Cannot use a static CharStream class with a non-static lexical analyzer.");
   input_stream = stream;
}
public OSmLPreParserTokenManager(SimpleCharStream stream, int lexState)
{
   this(stream);
   SwitchTo(lexState);
}
public void ReInit(SimpleCharStream stream)
{
   jjmatchedPos = jjnewStateCnt = 0;
   curLexState = defaultLexState;
   input_stream = stream;
   ReInitRounds();
}
private final void ReInitRounds()
{
   int i;
   jjround = 0x80000001;
   for (i = 11; i-- > 0;)
      jjrounds[i] = 0x80000000;
}
public void ReInit(SimpleCharStream stream, int lexState)
{
   ReInit(stream);
   SwitchTo(lexState);
}
public void SwitchTo(int lexState)
{
   if (lexState >= 1 || lexState < 0)
      throw new TokenMgrError("Error: Ignoring invalid lexical state : " + lexState + ". State unchanged.", TokenMgrError.INVALID_LEXICAL_STATE);
   else
      curLexState = lexState;
}

protected Token jjFillToken()
{
   Token t = Token.newToken(jjmatchedKind);
   t.kind = jjmatchedKind;
   String im = jjstrLiteralImages[jjmatchedKind];
   t.image = (im == null) ? input_stream.GetImage() : im;
   t.beginLine = input_stream.getBeginLine();
   t.beginColumn = input_stream.getBeginColumn();
   t.endLine = input_stream.getEndLine();
   t.endColumn = input_stream.getEndColumn();
   return t;
}

int curLexState = 0;
int defaultLexState = 0;
int jjnewStateCnt;
int jjround;
int jjmatchedPos;
int jjmatchedKind;

public Token getNextToken() 
{
  int kind;
  Token specialToken = null;
  Token matchedToken;
  int curPos = 0;

  EOFLoop :
  for (;;)
  {   
   try   
   {     
      curChar = input_stream.BeginToken();
   }     
   catch(java.io.IOException e)
   {        
      jjmatchedKind = 0;
      matchedToken = jjFillToken();
      return matchedToken;
   }

   jjmatchedKind = 0x7fffffff;
   jjmatchedPos = 0;
   curPos = jjMoveStringLiteralDfa0_0();
   if (jjmatchedKind != 0x7fffffff)
   {
      if (jjmatchedPos + 1 < curPos)
         input_stream.backup(curPos - jjmatchedPos - 1);
         matchedToken = jjFillToken();
         return matchedToken;
   }
   int error_line = input_stream.getEndLine();
   int error_column = input_stream.getEndColumn();
   String error_after = null;
   boolean EOFSeen = false;
   try { input_stream.readChar(); input_stream.backup(1); }
   catch (java.io.IOException e1) {
      EOFSeen = true;
      error_after = curPos <= 1 ? "" : input_stream.GetImage();
      if (curChar == '\n' || curChar == '\r') {
         error_line++;
         error_column = 0;
      }
      else
         error_column++;
   }
   if (!EOFSeen) {
      input_stream.backup(1);
      error_after = curPos <= 1 ? "" : input_stream.GetImage();
   }
   throw new TokenMgrError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, TokenMgrError.LEXICAL_ERROR);
  }
}

}
