import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		List<Serial> l = new ArrayList<>();
		for(int i=0; i<N; i++) {
			String s = sc.nextLine();
			l.add(new Serial(s));
		}
		Collections.sort(l);
		for(Serial s : l)
			System.out.println(s.serialNumber);
		sc.close();
	}
	
	private static class Serial implements Comparable<Serial>{
		private String serialNumber;

		public Serial(String serialNumber) {
			this.serialNumber = serialNumber;
		}

		@Override
		public int compareTo(Serial s) {
			if(this.serialNumber.length() < s.serialNumber.length())
				return -1;
			else if(this.serialNumber.length() > s.serialNumber.length())
				return 1;
			else {
				int x1 = 0, x2 = 0;
				for(int i=0; i<this.serialNumber.length(); i++) {
					if('1' <= this.serialNumber.charAt(i) && this.serialNumber.charAt(i) <= '9')
						x1 += this.serialNumber.charAt(i) - '0';
					if('1' <= s.serialNumber.charAt(i) && s.serialNumber.charAt(i) <= '9')
						x2 += s.serialNumber.charAt(i) - '0';
				}
				if(x1 < x2) return -1;
				else if(x1 > x2) return 1;
				else return this.serialNumber.compareTo(s.serialNumber);
			}
		}
	}
}
