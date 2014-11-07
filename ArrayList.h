#include <vector>
template <class T> class ArrayList
{
	private:
		vector<T> m_array;
	public:
		ArrayList();
		int size();
		void add(T item);
		T get(int index);	
		void remove(int index);	
};
template <class T> ArrayList<T>::ArrayList(){}

template <class T> int ArrayList<T>::size()
{
	return m_array.size();
}
template <class T> void ArrayList<T>::add(T item)
{
	m_array.push_back(item);
}
template <class T> T ArrayList<T>::get(int index)
{
	return m_array[index];
}
template <class T> void ArrayList<T>::remove(int index)
{
	m_array.erase(index);
}
