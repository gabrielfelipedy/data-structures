public class Main {

	public static void main(String[] args) {

		Queue q = new Queue();
		q.add(10);
		q.add(15);
		q.add(20);
		q.remove();
		System.out.println(q.peek());
	}
}
