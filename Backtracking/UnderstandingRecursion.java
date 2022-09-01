/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main {
  public static void recur(String s, String t, int i) {
  	if(i==s.length()) {
  		System.out.println(t);
  		return;
  	}
  	
  	//picked
  	recur(s,t+s.charAt(i), i+1);
  	
  	//skip
  	recur(s,t,i+1);
  }
}

class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		String s="abc"; //print all the subsequence 
		String t = "";

		
		Main.recur(s,t,0);
		
		/*
		abc => t=""
			picked a : t= "a"
			           picked b := t= "ab"
			                       picked c := t="abc"
			                       skipped c:= t= "ab"
			           skipped b := t= "a"
			                        picked c := t="ac"
			                        skipped c:= t= "a"
			skipped a : t= ""
			           picked b := t= "b"
			                       picked c := t="bc"
			                       skipped c:= t= "b"
			           skipped b := t= ""
			                        picked c := t="c"
			                        skipped c:= t= ""                         
			                       
		*/	
	 }
}
