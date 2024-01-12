#include<future>// furure promise model
#include<iostream>
 /*
 
                A       B       C   

                               *************  single thread technique************


                option 1 : one after the other.ALways complete one thing before starting the next task 
t

                option 2 :   i will complete all task in such a way that i practically all of them at the same time but 
                              keep juggling them on some  criteia
                                    
                              ************        multithread thecqnique
                 
                option 3 : map number of task amongs  number of avialable "workers"

                       ******************       parllel  execution


                option 4 :   start a task. either delegate to another worker or do it yourself after something 


                if someone doing a task , monitor it,wait for their  work to be done  ,take follow uo actions accordingly


                           Asynchronus execution 







                           square calculation 

                           m,ain needs to delegate  the task of sqaure  calculation  
 
 */



/*
  2 task
  calculate factorial of 5
  calculate square of a number given by user
*/



int square(std::future<int>& ft)
{
std::this_thread::sleep_for(std::chrono::seconds(2));
std::cout <<"Hello from Square  . I have started my work\n";
int number =ft.get();
return number*number;
}





int factorial(int number)
{
std::this_thread::sleep_for(std::chrono::seconds(3));
 if(number<0)
 {
    throw std::runtime_error("negatuve number");
 }

else if (number ==0 || number==1)
{
 return 1;
}

else 
{
    return number*factorial(number-1);
}

}




int main()
{      //step1 : make a promise 
     std::promise<int> pr;
      // step 2 :  a future linked  to the prmise
     std::future<int> ft= pr.get_future();

     /*
     os: launc square (if possible as a new thread )
     */
     std::future<int> result_ft= std::async(std::launch::async,&square ,std::ref(ft));
     std::cout <<factorial(5);
     int val=0;
     std::cin>>val;
     pr.set_value(val);
     std::cout<<"factorial is "<< result_ft.get();
}

