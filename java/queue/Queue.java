public class Queue {

	private static class Node {

		private int data;
		private Node next;
		private Node(int data) {
			this.data = data;
		}
	}

	private Node head;
	private Node tail;

	public boolean isEmpty() {
		return head == null;
	}

	public int peek() {
		return (head != null) ? head.data : tail.data;
	}

	public void add(int data) {

		Node node = new Node(data);
		if(head == null) {
			  head = node;
			  return;
		}

		if(tail != null) {
			tail.next = node;
			tail = node;
		}
	}

	public int remove() {

		int data = head.data;
		head = head.next;
		if(head == null) {
			tail = null;
		}

		return data;
	}
}
