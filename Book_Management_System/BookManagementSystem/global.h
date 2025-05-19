#pragma once
static class global
{
public:
    static bool isGoBackFromUserToMain;
    static bool isGoBackFromPersonnelToMain;

    static bool PersonalCollectionIsCreated;
// Enum For Models
    static enum class Models {
        model1=1,
        model2,
        model3,
        model4,
        model5,
        exit
    };


// Enums For Personnel Models :
    enum class PersonnelModel1Options {
        AddBook = 1,                  // 1.1
        EditBookByName ,           // 1.2
        DeleteBookById,           // 1.3
        ListBooksWithTimestamp,   // 1.4
        SearchBookById,           // 1.5
        GetTotalBookCount,        // 1.6
        SortBooksByPageCount,     // 1.7
        ShowOldest5Books,         // 1.8
        AddDamageNote,            // 1.9
        PrintDamagedBooks,       // 1.10
        Exit                    // 1.11
    };

    enum class PersonnelModel2Options {
        ReportBorrowedBooks = 1,      // 2.1
        ReportReturnedBooks,     // 2.2
        ListAvailableBooks ,       // 2.3
        Exit                     // 2.4
    };

    enum class PersonnelModel3Options {
        AddSuppliedBook =1,          // 3.1
        Exit                   // 3.2
    };

    enum class PersonnelModel4Options {
        AnalyzeBorrowDuration = 1,    // 4.1
        FilterByPublishYear ,      // 4.2
        FilterOldBooksLongBorrow , // 4.3
        Exit                    // 4.4
    };

    enum class PersonnelModel5Options {
        AddRatingsAndList = 1,        // 5.1
        Exit                    // 5.2
    };

// Enum For User Models :
    enum class UserModel1Options {
        AddCommentToBookByID = 1,                  // 2.1
        ListCommentsToBookByID ,                // 2.2
        CreateCollection ,            // 2.3
        AddBookToCollection ,             // 2.4
        MarkReadUnread ,              // 2.5
        RemoveBookFromCollectionByID ,        // 2.6
        PrintCollection ,             // 2.7
        Exit                         // 2.8
    };

    enum class UserModel2Options {
        BorrowBook = 1,                  // 2.1
        ListBorrowedBooks ,           // 2.2
        ReturnBook ,                  // 2.3
        ListReturnedBooks ,           // 2.4
        Exit                          // 2.5
    };

    enum class UserModel3Options {
        RequestBook = 1,                 // 2.1
        ViewRequests,                // 2.2
        AcademicRequest ,             // 2.3
        Exit                         // 2.4
    };

    enum class UserModel4Options {
        FilterByPublisher = 1,           // 2.1
        FilterByLanguage ,            // 2.2
        FilterByPageCount ,           // 2.3
        Exit                         // 2.4
    };

    enum class UserModel5Options {
        RecommendSimilarBooks = 1,       // 2.1
        RateBooksAndList ,            // 2.2
        Exit                         // 2.3
    };


    //book Language
    static enum class BookLanguages{turkish=1,english};
};


