// Workshop 9 - Smart Pointers
 // w9.cpp

 #include <iostream>
 #include <iomanip>
 #include <memory>
 #include "Element.h"
 #include "List.h"

 const int FWC =  5;
 const int FWD = 12;
 const int FWP =  8;

 w9::List<w9::Product> merge(const w9::List<w9::Description>& desc, 
  const w9::List<w9::Price>& price) {
     w9::List<w9::Product> priceList;
     //std::unique_ptr<w9::Product> p;
     //w9::Product* p;
     // complete this part
	for(size_t i = 0 ; i < price.size(); i++){
		for(size_t j = 0; j < desc.size(); j++){
			if(price[i].code == desc[j].code){
		std::unique_ptr<w9::Product> p(new w9::Product(desc[j].desc, price[i].price));	
				p->validate();
				priceList += std::move(p);	
					
			}
		}
	
	}
	
     return priceList;
 }

 int main(int argc, char** argv) {
     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 3) {
         std::cerr << "\n***Incorrect number of arguments***\n";
         return 1;
     }

     try {
         w9::List<w9::Description> desc(argv[1]);
         std::cout << std::endl;
         std::cout << std::setw(FWC) << "Code" <<
          std::setw(FWD) << "Description" << std::endl;
         std::cout << desc << std::endl;
         w9::List<w9::Price> price(argv[2]);
         std::cout << std::endl;
         std::cout << std::setw(FWC) << "Code" <<
          std::setw(FWP) << "Price" << std::endl;
         std::cout << price << std::endl;
         w9::List<w9::Product> priceList = merge(desc, price);
         std::cout << std::endl;
         std::cout << std::setw(FWD) << "Description" <<
          std::setw(FWP) << "Price" << std::endl;
         std::cout << priceList << std::endl;
     }
     catch (const std::string& msg) {
         std::cerr << msg << std::endl;
     }
     catch (const char* msg) {
         std::cerr << msg << std::endl;
     }

     std::cout << "\nPress any key to continue ... ";
     std::cin.get();
}
