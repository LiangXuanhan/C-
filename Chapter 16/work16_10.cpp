// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<memory>
    using namespace std;
struct Review {
    std::string title;
    double price;
    int rating;
};
bool operator<(const shared_ptr<Review> r1, const shared_ptr<Review>r2);
bool worseThan(const Review & r1, const Review & r2);
bool ratingworseThan(const shared_ptr<Review> r1, const shared_ptr<Review>r2);
bool priceworseThan(const shared_ptr<Review> r1, const shared_ptr<Review>r2);
bool FillReview(Review & rr);

bool ShowReview(shared_ptr<Review>  rr);
int main()
{

vector<shared_ptr<Review>> ptrbooks;
    vector<Review> books;

    Review temp;
    while (FillReview(temp))
    { shared_ptr<Review> tempp (new Review);
    tempp->price = temp.price;
    tempp->rating = temp.rating;
    tempp->title = temp.title;
    	ptrbooks.push_back(tempp);}
    if (ptrbooks.size() > 0)
    {
        cout << "Thank you. You entered  "
             << ptrbooks.size() << " ratings.\n";
			 vector<shared_ptr<Review>> titleseq(ptrbooks);
        	 vector<shared_ptr<Review>> ratingseq(ptrbooks);
        	 vector<shared_ptr<Review>> priceseq(ptrbooks);
        	 sort(titleseq.begin(), titleseq.end());
        	 sort(ratingseq.begin(), ratingseq.end(), ratingworseThan);
        	 sort(priceseq.begin(), priceseq.end(), priceworseThan);
              cout <<"Choose how to display: 1.original. 2. by title. 3. by rating 4. by rev-rating. 5. by price. 6. by rev-price";
       int choose;
       cin >> choose;
       while(choose!= 0)
       {
              switch(choose)
              { case 1:
            	  for_each(ptrbooks.begin(), ptrbooks.end(), ShowReview);
            	  break;
              case 2:
                          	  for_each(titleseq.begin(), titleseq.end(), ShowReview);
                          	  break;
              case 3:
                          	  for_each(ratingseq.begin(), ratingseq.end(), ShowReview);
                          	  break;
              case 4:
                          	  for_each(ratingseq.rbegin(), ratingseq.rend(), ShowReview);
                          	  break;
              case 5:
                          	  for_each(priceseq.begin(), priceseq.end(), ShowReview);
                          	  break;
              case 6:
                          	  for_each(priceseq.rbegin(), priceseq.rend(), ShowReview);
                          	  break;
              default:
            	  cout << endl << "Invalid choice. Choose again."<<endl;

              }
              cout <<"Choose how to display: 1.original. 2. by title. 3. by rating 4. by rev-rating. 5. by price. 6. by rev-price";

                    cin >> choose;
       }

cout << endl << "After sort by title." << endl;
		for_each(ptrbooks.begin(), ptrbooks.end(), ShowReview);
//        sort(books.begin(), books.end());
//        cout << "Sorted by title:\nRating\tBook\n";
//        for_each(books.begin(), books.end(), ShowReview);
//
//        sort(books.begin(), books.end(), worseThan);
//        cout << "Sorted by rating:\nRating\tBook\n";
//        for_each(books.begin(), books.end(), ShowReview);
//
//        random_shuffle(books.begin(), books.end());
//        cout << "After shuffling:\nRating\tBook\n";
//        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}



bool worseThan(const Review & r1, const Review & r2)
{
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

bool ShowReview(shared_ptr<Review>  rr)
{
    std::cout <<  rr->rating<< "\t" << rr->title  << "\t" << rr->price<< std::endl;
    return true;
}

bool operator<(const shared_ptr<Review> r1, const shared_ptr<Review>r2)
{
	if(r1->title < r2->title)
return true;
	 else if (r1->title == r2->title && r1->rating < r2->rating)
	        return true;
	 else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
	        return true;
	    else
	        return false;}


bool ratingworseThan(const shared_ptr<Review> r1, const shared_ptr<Review>r2)
{
	{
	if(r1->rating < r2->rating)
		return true;
	else
		return false;
	}
}
bool priceworseThan(const shared_ptr<Review> r1, const shared_ptr<Review>r2)
{
	{
	if(r1->price < r2->price)
		return true;
	else
		return false;
	}
}
