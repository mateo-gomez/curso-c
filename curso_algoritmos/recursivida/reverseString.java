public class ReverseString {
	public String stringReverse(String str) {
		if(str.isEmpty()) return str;

		return stringReverse(str.substring(1))+str.charAt(0);
	}

	public static void main(String[] args) {
		ReverseString obj = new ReverseString();

		String res = obj.stringReverse("hola mundo");

		System.out.println(res);
	}
}