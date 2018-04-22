import java.util.*;
import java.io.*;

class LeftRec{
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter the productions");
	String x = sc.nextLine();
	String [] pr = x.split("->");
	String [] prods = pr[1].split("\\|");

	String root = pr[0];
	String dash = pr[0]+"'";
	int [] flags = new int[prods.length];
	System.out.print(root+"->");
	for (int i=0;i<prods.length;i++) {
		// System.out.println(prods[i]);
		if(prods[i].indexOf(root)==0){
			flags[i]=1;
		}else{
			System.out.print(prods[i]+dash+"|");
		}

		
	}
	System.out.println();
	System.out.print(dash+"->");
	for (int i=0;i<prods.length ;i++ ) {
		if(flags[i]==1){
			System.out.print(prods[i].substring(1)+dash+"|");
		}		
	}
	System.out.println("#");;

	}
}