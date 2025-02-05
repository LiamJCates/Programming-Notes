package interfaces;

public interface IList<T> {

	/**
	 * Add a parameter value to the list.
	 * 
	 * @param value to be added to the list.
	 * @return Boolean representing whether the provided value was successfully added to the list.
	 */
	public boolean add(T value);

	/**
	 * Clear the list of all values.
	 */
	public void clear();

	/**
	 * Determine whether the list contains a parameter value
	 * 
	 * @param value to search list for.
	 * @return Boolean representing whether the list contains the provided value.
	 */
	public boolean contains(T value);

	/**
	 * Remove a parameter value from list.
	 * 
	 * @param value to be removed from list.
	 * @return Boolean representing whether the parameter value was removed.
	 */
	public boolean remove(T value);

	/**
	 * Determine size of the list.
	 * 
	 * @return Integer representing the current size of the list.
	 */
	public int size();
}