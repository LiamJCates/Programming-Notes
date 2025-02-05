package list;

import java.util.Arrays;

/**
 * A dynamic array, growable array, resizable array, dynamic table, or array
 * list is a random access, variable-size list data structure that allows
 * elements to be added or removed.
 */
@SuppressWarnings("unchecked")
public class ArrayList<T> extends List<T> {

	private static final int MINIMUM_SIZE = 1024;

	private int size = 0;
	private T[] array = (T[]) new Object[MINIMUM_SIZE];

	/**
	 * Add a parameter value to the list in parameter index.
	 * 
	 * @param Integer list index representing location to add value.
	 * @param value to be added to the list.
	 */
	public boolean add(int index, T value) {
		if (size >= array.length)
			grow();
		if (index == size) {
			array[size] = value;
		} else {
			// Shift the array down one spot
			System.arraycopy(array, index, array, index + 1, size - index);
			array[index] = value;
		}
		size++;
		return true;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean add(T value) {
		return add(size, value);
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void clear() {
		size = 0;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean contains(T value) {
		for (int i = 0; i < size; i++) {
			T obj = array[i];
			if (obj.equals(value))
				return true;
		}
		return false;
	}

	/**
	 * Get value at index.
	 * 
	 * @param index of value to get.
	 * @return value at index.
	 */
	public T get(int index) {
		if (index < 0 || index >= size)
			return null;
		return array[index];
	}

	// Grow the array by 50%
	private void grow() {
		int growSize = size + (size << 1);
		array = Arrays.copyOf(array, growSize);
	}

	/**
	 * Remove a value from the list in parameter index.
	 * 
	 * @param Integer list index representing location to remove value.
	 */
	public T remove(int index) {
		if (index < 0 || index >= size)
			return null;

		T t = array[index];
		if (index != --size) {
			// Shift the array down one spot
			System.arraycopy(array, index + 1, array, index, size - index);
		}
		array[size] = null;

		int shrinkSize = array.length >> 1;
		if (shrinkSize >= MINIMUM_SIZE && size < shrinkSize)
			shrink();

		return t;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean remove(T value) {
		for (int i = 0; i < size; i++) {
			T obj = array[i];
			if (obj.equals(value)) {
				remove(i);
				return true;
			}
		}
		return false;
	}

	/**
	 * Set value at index.
	 * 
	 * @param index of value to set.
	 * @param value to set.
	 * @return value previously at index.
	 */
	public T set(int index, T value) {
		if (index < 0 || index >= size)
			return null;
		T t = array[index];
		array[index] = value;
		return t;
	}

	// Shrink the array by 50%
	private void shrink() {
		int shrinkSize = array.length >> 1;
		array = Arrays.copyOf(array, shrinkSize);
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
		for (int i = 0; i < size; i++) {
			builder.append(array[i]).append(", ");
		}
		return builder.toString();
	}
}
