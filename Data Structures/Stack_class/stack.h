// Ikani Samani
// Project: Stack
//
// Disclaimer: 
// I Ikani Samani have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library.
// I understand that any violation of this disclaimer will result in a 0 for the project.
// ----------------------------------------------------------------------------------------------------
//


#include <cstdlib>
#include <cassert>

namespace samani_stack
{
	template <class t>
	class stack
	{
	public:
		// MEMBER CONSTANT

		static const int CAPACITY = 30;
		// CONSTRUCTOR
		stack() {used = 0;}
		// MODIFICATION MEMBER FUNCTIONS
		void push(const t& entry);
		void pop();
		// CONSTANT MEMBER FUNCTIONS
		bool empty() const {return (used == 0);}
		int size() const {return used;}
		t top() const;
	private:
		t data [CAPACITY];	// Partially filled array
		int used;			// How much of array is being used
	};

	template <class t>
	void stack <t>::push(const t& entry)
	// Library facilities used: cassert
	{
		assert(size() < CAPACITY);
		data[used] = entry;
		++used;
	}

	template <class t>
	void stack<t>::pop()
	// Library facilities used: cassert
	{
		assert(!empty());
		--used;
	}
	
	template <class t>
	t stack<t>::top() const
	// Library facilites used: cassert
	{
		assert(!empty());
		return data[used-1];
	}
}