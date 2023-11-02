// library management
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;
    const int finePerDay = 1;
    vector<string> issuedBooks;
    vector<int> dueDays;
    int totalBooks = 10;
    int borrowedBooks = 0;
    double fineAmount = 1.0;
    double totalFine = 0.0;

    while (true) {
        string userChoice;
        cout << "Library System Menu:" << endl;
        cout << "1. Borrow a book" << endl;
        cout << "2. Return a book" << endl;
        cout << "3. Exit" << std::endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (userChoice == "1") {
            cin.ignore();
            string bookTitle;
            cout << "Enter the title of the book: ";
            getline(cin, bookTitle);

            if (borrowedBooks < totalBooks) {
                issuedBooks.push_back(bookTitle);
                dueDays.push_back(3); // Initialize with 3 days before fine.
                borrowedBooks++;
                cout << "Book '" << bookTitle << "' borrowed successfully." << endl;
                cout << "Due date: " << dueDays.back() << " days from today." << endl;
            }
            else {
                cout << "The library is at full capacity. Cannot borrow more books." << endl;
            }
        }
        else if (userChoice == "2") {
            cin.ignore();
            string bookTitle;
            cout << "Enter the title of the book to return: ";
            getline(cin, bookTitle);

            bool bookFound = false;
            int returnDays = 0;
            for (size_t i = 0; i < issuedBooks.size(); i++) {
                if (issuedBooks[i] == bookTitle) {
                    bookFound = true;
                    cout << "Enter the return date (days from due date): ";
                    cin >> returnDays;

                    if (returnDays <= dueDays[i]) {
                        cout << "Book '" << bookTitle << "' returned on time. No fines incurred." << endl;
                    }
                    else {
                        int daysLate = returnDays - dueDays[i];
                        double fine = daysLate * fineAmount;
                        totalFine += fine;
                        cout << "Fine for returning " << daysLate << " days late: $" << fine << endl;
                    }

                    issuedBooks.erase(issuedBooks.begin() + i);
                    dueDays.erase(dueDays.begin() + i);
                    borrowedBooks--;
                    break;
                }
            }

            if (!bookFound) {
                cout << "The book is not found or has not been borrowed." << endl;
            }
        }
        else if (userChoice == "3") {
            cout << "Exiting the Library System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    cout << "Total fine collected: $" << totalFine << endl;

    return 0;
}