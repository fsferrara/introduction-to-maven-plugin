public class Ackermann {
	
	static long count = 0;
	
	private static long h(long m, long n) {
		
		count++;
		
		if (m == 0) {
			return n + 1;
		}

		if (n == 0) {
			return h(m-1, 1);
		}
		
		return h(m-1, h(m,n-1) );
	}
	
	private static long ack(long n) {
		return h(n, n);
	}

	public static void main(String[] args) {
		
		if (args.length != 1) {
			System.out.println("usage: Ackermann <number>\n\twhere number is a positive integer");
			System.exit(1);
		}
		
		long n = Long.valueOf(args[0]);
		
		count = 0;
		long retValue = ack(n);		
		System.out.println("ack(" + n + ") = " + retValue + " [recursive calls = "+ count +"]");

		
		System.exit(0);
	}

}
