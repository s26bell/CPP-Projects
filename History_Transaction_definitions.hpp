#ifndef _HISTORY_TRANSACTION_HPP_
#define _HISTORY_TRANSACTION_HPP_

#include <cassert>
#include <iomanip>
#include <iostream>

#include "project3.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK
//
 Transaction::Transaction(std::string ticker_symbol, unsigned int day_date,
              unsigned int month_date, unsigned year_date, bool buy_sell_trans,
              unsigned int number_shares, double trans_amount) :

	  day {day_date},
	  month {month_date},
	  year {year_date},
	  shares{number_shares},
	  amount{trans_amount},
	  acb{0},
	  acb_per_share{0},
	  share_balance{0},
	  cgl{0}

	  {
		  symbol =ticker_symbol;
		  if (buy_sell_trans)
		  {
			  trans_type = "Buy";
		  }
		  else
		  {
			trans_type = "Sell";
		  }

		 p_next = nullptr;
		 trans_id = assigned_trans_id;
		 ++ assigned_trans_id;
	  }


// Destructor
// TASK
//

  Transaction::~Transaction() {

		  p_next = nullptr;
	  }


// TASK
// Overloaded < operator.
//
//Transaction 1 < Transaction 2

	bool Transaction::operator<(Transaction const &other) {
		  if (Transaction::year < other.get_year()  ){
			  return true;
		  }
		  if ( Transaction::year > other.get_year()){
			  return false;
		  }
		  if (Transaction::month < other.get_month()){
			  return true;
		  }
		  if ( Transaction::month > other.get_month()){
			  return false;
		  }
		  if ( Transaction::day <  other.get_day()){
			  return true;
		  }
		  else {
			  return false;
		  }

	  }
// GIVEN
// Member functions to get values. 
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values. 
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " " 
    << std::setw(4) << get_symbol() << " " 
    << std::setw(4) << get_day() << " "  
    << std::setw(4) << get_month() << " " 
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) { 
    std::cout << "  Buy  "; 
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " " 
    << std::setw(10) << get_amount() << " " 
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl() 
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK
//
    History::History()

    {p_head = nullptr;}


// Destructor
// TASK
//
    History::~History() {

    	 Transaction *p_store{nullptr};  //Change after submission

    	if (p_head!=nullptr ){
    		 while (p_head->get_next() != nullptr){

    		     p_store = p_head;
    		     p_head = p_head->get_next();
    		     delete p_store;
    		     p_store = nullptr; //Change after submission

    		  }

    		    	  delete p_head;
    		    	  p_head = nullptr;
    	}


      }


// TASK
// read_transaction(...): Read the transaction history from file. 
//
    void History::read_history() {

    	  Transaction *p_transaction_current{nullptr};

    	 ece150::open_file();

    	  while (ece150::next_trans_entry()){

    		  p_transaction_current = new Transaction (ece150::get_trans_symbol(), ece150::get_trans_day(),ece150::get_trans_month(),
    				                                    ece150::get_trans_year(),ece150::get_trans_type(),
														ece150::get_trans_shares(), ece150::get_trans_amount());


    		 insert (p_transaction_current);


    	  }

    	 ece150::close_file();



      }


// insert(...): Insert transaction into linked list.
//

    void History::insert(Transaction *p_new_trans) {

    	  Transaction *p_sort = p_head;


    	  if (p_head == nullptr)
    	  {
    		  p_head = p_new_trans;
    		  p_new_trans->set_next(nullptr);
    	  }
    	  else
    	  {
    		  while(p_sort->get_next() != nullptr)
    		  {
    			  p_sort = p_sort->get_next();
    		  }

    		  p_sort->set_next(p_new_trans);
    	  }

      }


// TASK
// sort_by_date(): Sort the linked list by trade date.
//


    void  History::sort_by_date() {

    	  Transaction *p_head_sorted{nullptr};
    	  Transaction *p_head_move{nullptr};
    	  Transaction *p_head_check{nullptr};

    	  if(p_head!=nullptr){


    		  p_head_sorted = p_head;
    		  p_head = p_head->get_next();
    		  p_head_sorted->set_next(nullptr);


    		 while (p_head!=nullptr){

    			  p_head_move = p_head;
    			  p_head = p_head->get_next();
    			  p_head_move->set_next(nullptr);

    			  p_head_check = p_head_sorted;

    			  if (*p_head_move < *p_head_sorted){
    						//Insert at begining of list
    				  p_head_move->set_next(p_head_sorted);
    				  p_head_sorted = p_head_move;
    				  continue;
    			  }

    			  while (p_head_check!=nullptr){


    				  if (p_head_check->get_next() == nullptr){
    				 	//Insert p_head_move at end

    					p_head_check->set_next(p_head_move);

    					break;

    				  }

    				  else if(*p_head_move < *(p_head_check->get_next())){
    					  //Insert p_head_move

    					  p_head_move->set_next(p_head_check->get_next());
    					  p_head_check->set_next(p_head_move);

    					  break;
    				  }

    				  p_head_check = p_head_check->get_next();

    			  	  }//End of while loop

    		   }//End of While Loop

    		 p_head = p_head_sorted;

    	}//End of If

    }



// TASK
// update_acb_cgl(): Updates the ACB and CGL values.
//
    void  History::update_acb_cgl() {

    	  //Update acb
    	  //Update abc_per_share
    	  //Update cgl
    	  //Update share balance

    	  Transaction *p_updater = p_head;
    	 long double sum_acb{0};
    	 long unsigned int sum_sharebalance{0};
    	 long  double acb_per_share{0};



    	  while (p_updater!=nullptr){


    		  if(p_updater->get_trans_type()){ // Updates on a buy

    			sum_sharebalance += p_updater->get_shares();  //Updating share balance
    			p_updater->set_share_balance(sum_sharebalance);

    			sum_acb += p_updater->get_amount(); //Updating acb
    			p_updater->set_acb(sum_acb);

     			p_updater->set_acb_per_share(sum_acb/sum_sharebalance); //Updating acb per share
     			acb_per_share = sum_acb/sum_sharebalance;


    	     }
    	    else{ // Updates on a buy

    	      p_updater->set_acb_per_share(acb_per_share); //Setting

    		  sum_acb = sum_acb - ((p_updater->get_shares()) * (p_updater->get_acb_per_share())); //Updates acb share
    		  p_updater->set_acb(sum_acb);

    		  sum_sharebalance -= p_updater->get_shares();  //Updating share balance
    		  p_updater->set_share_balance(sum_sharebalance);

    		  p_updater->set_acb_per_share(acb_per_share); //Setting

    		  p_updater->set_cgl(p_updater->get_amount() - (p_updater->get_shares()*p_updater->get_acb_per_share()));

    	  }
    		  p_updater = p_updater->get_next();
    	  }

      }


// TASK
// compute_cgl(): )Compute the ACB, and CGL.
//
    double  History::compute_cgl(unsigned int year) {

    	long double cgl_year{0};
    	  Transaction *p_cgl = p_head;
    	  while (p_cgl!=nullptr){

    		  if(p_cgl->get_year() == year){
    			  cgl_year += p_cgl->get_cgl();
    		  }


    		  p_cgl = p_cgl->get_next();

    	  }

    	  return cgl_year;
      }




// TASK
// print() Print the transaction history.
//
    void  History::print() {
    	  Transaction *p_print = p_head;
    	 std::cout<<"========== BEGIN TRANSACTION HISTORY ============"<<std::endl;

    	  while(p_print!=nullptr){
    		  p_print->print();
    		  p_print=p_print->get_next();
    	  }
    	  std::cout<<"========== END TRANSACTION HISTORY ============ "<<std::endl;
      }

// GIVEN
// get_p_head(): Full access to the linked list.
// 
Transaction *History::get_p_head() { return p_head; }


#endif

