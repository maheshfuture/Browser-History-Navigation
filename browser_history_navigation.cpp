#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;    // Stores previous pages
    stack<string> forwardStack; // Stores forward pages
    string currentPage;         // Current page being visited

public:
    // Constructor: Start with a home page
    BrowserHistory(const string& homepage) {
        currentPage = homepage;
        cout << "Browser started at: " << homepage << endl;
    }

    // Visit a new page
    void visit(const string& url) {
        backStack.push(currentPage); // Save the current page to back stack
        currentPage = url;          // Update current page
        while (!forwardStack.empty()) {
            forwardStack.pop();     // Clear forward stack when visiting a new page
        }
        cout << "Visited: " << currentPage << endl;
    }

    // Go back to the previous page
    void back() {
        if (backStack.empty()) {
            cout << "No pages to go back to!\n";
            return;
        }
        forwardStack.push(currentPage); // Save the current page to forward stack
        currentPage = backStack.top(); // Restore the last page from back stack
        backStack.pop();
        cout << "Went back to: " << currentPage << endl;
    }

    // Go forward to the next page
    void forward() {
        if (forwardStack.empty()) {
            cout << "No pages to go forward to!\n";
            return;
        }
        backStack.push(currentPage);    // Save the current page to back stack
        currentPage = forwardStack.top(); // Restore the next page from forward stack
        forwardStack.pop();
        cout << "Went forward to: " << currentPage << endl;
    }

    // Display the current page
    void display() const {
        cout << "Current Page: " << currentPage << endl;
    }
};

int main() {
    BrowserHistory browser("homepage.com");

    browser.visit("google.com");
    browser.visit("github.com");
    browser.visit("stackoverflow.com");

    browser.back();    // Back to github.com
    browser.back();    // Back to google.com
    browser.forward(); // Forward to github.com
    browser.visit("cppreference.com"); // Visit a new page, clears forward history
    browser.back();    // Back to github.com
    browser.forward(); // Forward to cppreference.com
    browser.display(); // Show the current page

    return 0;
}
