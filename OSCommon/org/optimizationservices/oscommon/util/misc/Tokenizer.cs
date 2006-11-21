//Tokenizer.cs
//
//	RealFree(TM) License.
// The Licensee is granted to use this code freely under the
// condition that the author's name is retained. The Licensee
// is granted to use, modified, distributed, and commercialize
// the code freely, except the original source code provided
// herein is owned by
//
//	Copyright (c) 2001
// Gary L. Sun
// gsun@inetnow.net
// Aug. 26, 2001
//
namespace org.optimizationservices.oscommon.util.misc {
	///<summary>
	///	A simple tokenizer in csharp without using
	///	regex or MatchCollections
	///
	///	It accepts single string input. The string can
	///	contain multiple tokens or tags to be parsed.
	///	The delimiter can be any character.
	///
	///	It works by create a new instance and use GetToken
	///	to get the first token back, use MoveToNext furhter
	///	on. The first GetToken call will automatically position
	///	to the beginning of the input string. There is no
	///	to call MoveToNext to do the same job!
	///
	///	The characters to be bypassed can be added or modified
	///	to the char[] BYPASSCODE in unicode, hex, or character
	///	formats.
	///</summary>
	using System;
	using System.IO;

	public class Tokenizer {
		///<summary>
		///	DELIMITER is used to hold the input parameter
		///	delimiter when calling GetToken.
		///	strTokenBuffer is used to hold the unparsed string
		///	and used as input string for MoveToNext method call.
		///	char [] BYPASSCODE is used to hold codes to be
		///	by passed without parsing.
		///</summary>
		private static char DELIMITER = ' ';
		private static string strTokenbuffer;
		private static char[] BYPASSCODE = {'\u0009',' ','\v'};
		public Tokenizer() {

		}
		///<summary>
		///	GetToken - the first call to position to the
		///	beginning of the input string and send cack
		///	the first token.
		///</summary>
		///	<returns>first token in string type</returns>
		///	<param name="line">input string to be parsed.</param>
		///	<param name="delimiter">delimiter used to parse line.</param>

		public string GetToken(string line, char delimiter) {

			return ParseToken(line, delimiter);
		}
		///<summary>
		///	MoveToNext - following calls to GetToken to get
		///	back the remaining tokens from the input string.
		///</summary>
		///<returns>token in string type</returns>
		///<param>none</parm>
		public string MoveToNext() {
			return ParseToken(strTokenbuffer, DELIMITER);
		}
		///<summary>
		///	ParseToken - code to actualy parse the string using
		///	the specified delimiter.
		///</summary>
		///<returns>token in string type</returns>
		///<param name="line">input string (string)</parm>
		///<param name="delimiter">delimiter used for parsing (char)</param>
		public string ParseToken(string line, char delimiter) {
			int i = 0;
			int j = line.Length;
			bool foundFg = false;

			char[] p;
			int k;

			if(String.Compare(line, String.Empty) == 0) {
				return(null);
			}
			p = line.ToCharArray();

			do {
				for(int ii = 0; ii < BYPASSCODE.Length; ii++) {
					if( p[i] == BYPASSCODE[ii] ) {
						foundFg = true;
						break;
					}
				}
				if( foundFg ) {
					i++;
					foundFg = false;
				}
				else
					break;
			} while(i < j);

			k = i;
			while(i < j && p[i] != delimiter) {
			 i++;}
			strTokenbuffer = line.Substring(i,  j-i);

			return(line.Substring(k, i-k));
		}
		///<summary>
		///	Main - test code or entry point.
		///</summary>
		public static void Main(string[] args) {
			Tokenizer x = new Tokenizer();
			string s = x.GetToken(args[0], ' ');
			while(s != null) {
				Console.WriteLine("output:" + s);
				s = x.MoveToNext();
			}
		}
	}
}

