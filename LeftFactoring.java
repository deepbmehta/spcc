import java.util.*;
import java.io.*;

class LeftFactoring{

	public static void main(String args[]) throws IOException{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		List<String> rules = new ArrayList<String>();
		String[] productions = new String[] {"E->aACD", "E->aABE", "E->aADFC"};
		for(String x : productions){
			rules.add(x.split("->")[1]);
		}
		for (String str : rules) {
			System.out.println(str);
		}
		int length = 1000;
		String temp=null;
		for(int i=0;i<rules.size();i++){
			String x = rules.get(i);
			if(x.length() < length){
				length = x.length();
				temp = x;
			}
		}
		System.out.println("Smallest length string is:"+temp);
		int j = 0;
		int i = 0;
		int flag = 0;

		while(flag!=1){
			for(i=0;i<rules.size();i++){
				if(rules.get(i).contains(temp)){
					flag = 0;
				}
				else{
					break;
				}
			}
			if(i==rules.size()){
				flag = 1;
				System.out.println(productions[0].charAt(0)+"->"+temp);
				System.out.print(productions[0].charAt(0)+"'->");
				for(i=0;i<rules.size();i++){
					System.out.print(rules.get(i).substring(temp.length(),rules.get(i).length())+"|");
				}
			}
			else{
				temp = temp.substring(0,temp.length()-1);
			}
		}
		System.out.println();
	}
}