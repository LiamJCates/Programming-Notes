package list;

/**
 * Linked List (Singly link). A linked list is a data structure consisting of a
 * group of nodes which together represent a sequence.
 */
public class SinglyLinkedList<T> extends List<T> {

	private static class Node<T> {

		private T value = null;
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
			return "value=" + value + " next=" + ((next != null) ? next.value : "NULL");
		}
	}
	private int size = 0;
	private Node<T> head = null;

	private Node<T> tail = null;

	/**
	 * Add node to list.
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
		Node<T> prev = null;
		Node<T> node = head;
		while (node != null && (!node.value.equals(value))) {
			prev = node;
			node = node.next;
		}

		if (node == null)
			return false;

		// Update the tail, if needed
		if (node.equals(tail)) {
			tail = prev;
			if (prev != null)
				prev.next = null;
		}

		Node<T> next = node.next;
		if (prev != null && next != null) {
			prev.next = next;
		} else if (prev != null && next == null) {
			prev.next = null;
		} else if (prev == null && next != null) {
			// Node is the head
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