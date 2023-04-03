public class LinkedList {

        Node head;

	public String toString() {

		Node copy = head;
		String back = "";
		if(copy == null) {
			back = "No data";
		} else {

			while(true) {
				back += copy.data;
				back += "\n";
				if(copy.next == null) {	
					break;
				}
				copy = copy.next;
			}
		}
		return back;
	}

        public void append(int data) {

                if(head == null) {
                        head = new Node(data);
                        return;
                }

                Node current = head;

                while(current.next != null) {

                        current = current.next;
                }

                current.next = new Node(data);
		System.out.println("Value " + data + " added");
        }

        public void prepend(int data) {

                Node newHead = new Node(data);
                newHead.next = head;
                head = newHead;
        }

        public void delete(int data) {

                if(head == null) return;
                if(head.data == data) {
                        head = head.next;
                        return;
                }

                Node current = head;
                while(current.next != null) {
                        if(current.next.data == data) {

                                current.next = current.next.next;
                                return;
                        }

                        current = current.next;
                }
        }
}
