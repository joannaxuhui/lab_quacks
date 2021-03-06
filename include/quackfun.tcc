/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace quackfun
{

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the standard library stack in this problem. Its pop
 * function works a bit differently from the stack we built. Try searching
 * for "stl stack" to learn how to use it.
 *
 * @hint Think recursively!
 */
template <typename T>
T sum(std::stack<T>& s)
{   if(s.empty())
    {
		
 		return 0;
    }

    else
     {
		 T a =s.top();
		 s.pop();
         T mysum=sum(s);
		 s.push(a);
         return mysum+a; 
         
		 
     }     
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the standard library queue in this problem. Its pop
 * function works a bit differently from the stack we built. Try searching
 * for "stl stack" to learn how to use it.
 *
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(std::queue<T>& q)
{   using namespace std;
	stack<T> ss;
	for(size_t i=1;i*(i+1)/2<q.size()+1;i++)
	{
		size_t count=i;
		size_t num=count;
		while(count%2==1&&num)
		{
			T temp1=q.front();
			q.pop();
            q.push(temp1);
			num--;
		}
		while(count%2==0&&num)
		{
			T temp1=q.front();
            q.pop();
            ss.push(temp1);
			num--;
		}
       while(!ss.empty())
		{
			T temp1=ss.top();
			ss.pop();
			q.push(temp1);
		}
	 if(i*(i+1)/2<q.size()&& (i+1)*(i+2)/2>q.size())
      {
       size_t m=q.size()-i*(i+1)/2;
       size_t n=m;
        while(m%2==1&&n)
        {
			T temp1=q.front();
			q.pop();
            q.push(temp1);
			n--;	
		}
		while(m%2==0&&n)
		{
			T temp1=q.front();
            q.pop();
            ss.push(temp1);
			n--;
		}
       while(!ss.empty())
		{
			T temp1=ss.top();
			ss.pop();
			q.push(temp1);
           
		}

      }	
	}
	
}

/**
 * @return true if the parameter stack and queue contain only elements of
 * exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 *
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to
 *   use in your return statement, and you may only declare TWO local
 *   variables of parametrized type T to use however you wish.
 *   No other local variables can be used.
 * - After execution of verify_same, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verify_same(std::stack<T>& s, std::queue<T>& q)
{   using namespace std;
   if(s.empty())
   {   
	return true;
   }
   else
   {
		T temp=s.top();
		s.pop();
		bool b= verify_same(s,q);
		s.push(temp);
        T temp2=q.front();
        q.pop();
        q.push(temp2);
       return temp==temp2&&b;
    /*   T temp1=s.top();
	T temp2=q.front();
     if(temp1!=temp2)
    return false;
    else{

        s.pop();
		q.pop();
		verify_same(s,q);
         s.push(temp1);
		q.push(temp2);
		return true;
      }*/
    

	}	
     
}

}
