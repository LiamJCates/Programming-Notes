package list;

/**
 * Linked List (doubly link). A linked list is a data structure consisting of a
 * group of nodes which together represent a sequence.
 * <p>
 * 
 * @see <a href="https://en.wikipedia.org/wiki/Linked_list">Linked List
 *      (Wikipedia)</a> <br>
 * @author Justin Wetherell <phishman3579@gmail.com>
 */
public class DoublyLinkedList<T> extends List<T> {

	private static class Node<T> {

		private T value = null;
		private Node<T> prev = null;
		private Node<T> next = null;

		private Node() {
		}

		private Node(T value) {
			this.value = value;
		}

		/**
		 * {@inheritDoc}
		 */
		@Override
		public String toString() {
			return "value=" + value + " previous=" + ((prev != null) ? prev.value : "NULL") + " next="
					+ ((next != null) ? next.value : "NULL");
		}
	}

	private int size = 0;
	private Node<T> head = null;
	private Node<T> tail = null;

	/**
	 * Add parameter node to list.
	 * 
	 * @param node to add to list.
	 */
	private boolean add(Node<T> node) {
		if (head == null) {
			head = node;
			tail = node;
		} else {
			Node<T> prev = tail;
			prev.next = node;
			node.prev = prev;
			tail = node;
		}
		size++;
		return true;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean add(T value) {
		return add(new Node<T>(value));
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void clear() {
		head = null;
		size = 0;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean contains(T value) {
		Node<T> node = head;
		while (node != null) {
			if (node.value.equals(value))
				return true;
			node = node.next;
		}
		return false;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean remove(T value) {
		// Find the node
		Node<T> node = head;
		while (node != null && (!node.value.equals(value))) {
			node = node.next;
		}
		if (node == null)
			return false;

		// Update the tail, if needed
		if (node.equals(tail))
			tail = node.prev;

		Node<T> prev = node.prev;
		Node<T> next = node.next;
		if (prev != null && next != null) {
			prev.next = next;
			next.prev = prev;
		} else if (prev != null && next == null) {
			prev.next = null;
		} else if (prev == null && next != null) {
			// Node is the head
			next.prev = null;
			head = next;
		} else {
			// prev==null && next==null
			head = null;
		}
		size--;
		return true;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public int size() {
		return size;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		Node<T> node = head;
		while (node != null) {
			builder.append(node.value).append(", ");
			node = node.next;
		}
		return builder.toString();
	}
}