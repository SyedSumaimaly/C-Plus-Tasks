#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Question
{
    string questionText;
    vector<string> options;
    int correctOption;
};

// Simulated user database
map<string, string> userDatabase;

// Function to register a new user
void registerUser()
{
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    if (userDatabase.find(username) != userDatabase.end())
    {
        cout << "Username already exists. Please try a different username.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;
    userDatabase[username] = password;
    cout << "Registration successful! You can now log in.\n";
}

// Function to log in a user
bool loginUser()
{
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password)
    {
        cout << "Login successful! Welcome, " << username << ".\n";
        return true;
    }

    cout << "Invalid username or password. Please try again.\n";
    return false;
}

// Function to load questions for each category and difficulty
vector<Question> loadQuestions(int category, int difficulty)
{
    vector<Question> questions;
    if (category == 1)
    {
        if (difficulty == 1)
        {
            questions = {
                {"What does HTML stand for?",
                 {"Hyper Text Markup Language", "Hyperlinks Text Markup Language", "Home Tool Markup Language", "Hyperlinks and Text"},
                 1},
                {"Which tag is used to create a hyperlink?",
                 {"<link>", "<a>", "<href>", "<hlink>"},
                 2},
                {"Which CSS property changes text color?",
                 {"color", "background-color", "font-color", "text-color"},
                 1},
                {"Which tag is used to define an image?",
                 {"<img>", "<picture>", "<image>", "<photo>"},
                 1},
                {"What is the purpose of the <title> tag?",
                 {"Defines the document's title", "Sets font size", "Links CSS", "Inserts images"},
                 1},
            };
        }
        else if (difficulty == 2)
        {
            questions = {
                {"Which property sets the background color?",
                 {"bgcolor", "background-color", "color", "bg"},
                 2},
                {"Which HTML element is used for the largest heading?",
                 {"<h1>", "<heading>", "<h6>", "<head>"},
                 1},
                {"Which CSS property changes font size?",
                 {"font-size", "text-size", "size", "font"},
                 1},
                {"How do you add a comment in HTML?",
                 {"<!-- Comment -->", "// Comment", "/* Comment */", "# Comment"},
                 1},
                {"Which attribute is used to define inline styles in HTML?",
                 {"style", "class", "id", "inline"},
                 1},
            };
        }
        else if (difficulty == 3)
        {
            questions = {
                {"What is the default position of an element in CSS?",
                 {"static", "relative", "absolute", "fixed"},
                 1},
                {"Which pseudo-class is used to style visited links?",
                 {":link", ":visited", ":hover", ":active"},
                 2},
                {"How do you select elements with the class name 'box' in CSS?",
                 {"#box", ".box", "box", "::box"},
                 2},
                {"What does the z-index property control?",
                 {"Layer order", "Transparency", "Width", "Font size"},
                 1},
                {"Which HTML attribute is used to define a tooltip?",
                 {"alt", "title", "tooltip", "hover"},
                 2},
            };
        }
    }
    else if (category == 2)
    {
        if (difficulty == 1)
        {
            questions = {
                {"What is Remix?",
                 {"A JavaScript library", "A full-stack web framework", "A CSS framework", "A testing library"},
                 2},
                {"Which language is used with Remix for development?",
                 {"Python", "JavaScript", "Ruby", "PHP"},
                 2},
                {"What is the default file extension for Remix route files?",
                 {".js", ".jsx", ".route.js", ".remix"},
                 2},
                {"What kind of applications does Remix specialize in?",
                 {"Command-line tools", "Static websites", "Interactive web applications", "Mobile apps"},
                 3},
                {"What is the key advantage of Remix?",
                 {"Server-side rendering", "Reduced page loading times", "Better SEO", "All of the above"},
                 4},
            };
        }
        else if (difficulty == 2)
        {
            questions = {
                {"What is the purpose of Remix actions?",
                 {"To fetch data from an API", "To handle form submissions", "To manage state in the application", "To style components"},
                 2},
                {"How does Remix handle nested routing?",
                 {"Through file-based routing", "By manually defining routes in app.js", "Using React context", "With dynamic imports"},
                 1},
                {"What does the remix.config.js file define?",
                 {"Application settings", "Database configuration", "API endpoints", "Server settings"},
                 1},
                {"How are environment variables used in Remix?",
                 {"By importing dotenv", "Through process.env", "By creating .env files", "All of the above"},
                 4},
                {"What library does Remix use for styling by default?",
                 {"Tailwind CSS", "Styled-components", "Vanilla Extract", "Bootstrap"},
                 3},
            };
        }
        else if (difficulty == 3)
        {
            questions = {
                {"What is the primary difference between loader and action in Remix?",
                 {"loader handles GET requests, action handles POST requests", "loader handles both GET and POST requests, action is for PUT requests", "loader is client-side only, action is server-side", "There is no difference"},
                 1},
                {"How does Remix implement progressive enhancement?",
                 {"By bundling JavaScript separately", "By ensuring forms and links work without JavaScript", "By using service workers", "By optimizing CSS loading"},
                 2},
                {"What is a Remix meta function used for?",
                 {"To define metadata for routes", "To manage route-specific state", "To fetch server-side data", "To configure middleware"},
                 1},
                {"What is the purpose of defer in Remix loaders?",
                 {"To delay data fetching until user interaction", "To load data asynchronously while rendering", "To defer route transitions", "To lazy-load images"},
                 2},
                {"How does Remix handle caching for loaders?",
                 {"Using HTTP headers", "By saving data to local storage", "Through service workers", "By revalidating on every request"},
                 1},
            };
        }
    }
    else if (category == 3)
    {
        if (difficulty == 1)
        {
            questions = {
                {"What is React Native?",
                 {"A framework for building mobile apps", "A library for React web apps", "A CSS framework", "A state management library"},
                 1},
                {"Which language is primarily used with React Native?",
                 {"JavaScript", "Python", "Ruby", "Swift"},
                 1},
                {"What is the default way to style components in React Native?",
                 {"CSS files", "Inline styles", "StyleSheet API", "Bootstrap"},
                 3},
                {"Which tag is commonly used for layout in React Native?",
                 {"<div>", "<span>", "<View>", "<Layout>"},
                 3},
                {"How are components created in React Native?",
                 {"Using Java classes", "With React components", "By writing Swift code", "Through XML templates"},
                 2},
            };
        }
        else if (difficulty == 2)
        {
            questions = {
                {"What is the purpose of the FlatList component in React Native?",
                 {"To display lists of data", "To create forms", "To manage navigation", "To handle animations"},
                 1},
                {"How do you manage navigation in React Native?",
                 {"Using React Router", "With the Navigator API", "By installing React Navigation", "With Redux"},
                 3},
                {"What is the purpose of the useEffect hook in React Native?",
                 {"To manage side effects in a component", "To handle animations", "To define component styles", "To interact with hardware sensors"},
                 1},
                {"Which API is used for managing gestures in React Native?",
                 {"React Gesture Handler", "React Animated API", "PanResponder", "All of the above"},
                 4},
                {"What is the advantage of Expo in React Native?",
                 {"Easier setup and development", "Smaller app size", "Enhanced performance", "Built-in database"},
                 1},
            };
        }
        else if (difficulty == 3)
        {
            questions = {
                {"How does React Native achieve native performance?",
                 {"By using WebViews", "Through JavaScript bridges to native code", "By compiling to machine code", "By bundling CSS files"},
                 2},
                {"What is the difference between React Native CLI and Expo?",
                 {"Expo offers a simpler setup, but less native customization", "React Native CLI is for web apps, Expo is for mobile apps", "Expo is for production, React Native CLI is for testing", "There is no difference"},
                 1},
                {"How is state management typically handled in large React Native apps?",
                 {"By using useState only", "Through Redux or Context API", "With local storage", "By creating global variables"},
                 2},
                {"Which React Native library is used for animations?",
                 {"React Animated API", "Lottie", "React Spring", "All of the above"},
                 4},
                {"What is the purpose of Code Push in React Native?",
                 {"To improve app startup time", "To deploy updates without app store approval", "To compress app assets", "To manage app dependencies"},
                 2},
            };
        }
    }

    return questions;
}

int main()
{
    cout << "Welcome to the Quiz Application!" << endl;

    // Authentication menu
    bool isAuthenticated = false;
    while (!isAuthenticated)
    {
        cout << "1. Register\n";
        cout << "2. Log in\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            isAuthenticated = loginUser();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    // Category selection
    cout << "Select a category:\n";
    cout << "1. HTML & CSS\n";
    cout << "2. Remix\n";
    cout << "3. React Native\n";
    int categoryChoice;
    cin >> categoryChoice;

    // Difficulty selection
    cout << "Select difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    int difficultyChoice;
    cin >> difficultyChoice;

    // Load questions
    vector<Question> questions = loadQuestions(categoryChoice, difficultyChoice);
    if (questions.empty())
    {
        cout << "No questions found for the selected category and difficulty. Exiting.\n";
        return 1;
    }

    // Start quiz
    int score = 0;
    for (size_t i = 0; i < questions.size(); ++i)
    {
        cout << "Q" << i + 1 << ": " << questions[i].questionText << endl;
        for (size_t j = 0; j < questions[i].options.size(); ++j)
        {
            cout << j + 1 << ". " << questions[i].options[j] << endl;
        }

        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == questions[i].correctOption)
        {
            cout << "Correct!\n";
            ++score;
        }
        else
        {
            cout << "Wrong! The correct answer was: "
                 << questions[i].options[questions[i].correctOption - 1] << endl;
        }
        cout << endl;
    }

    // Display final score
    cout << "Quiz Over! Your final score is: " << score << "/" << questions.size() << endl;

    return 0;
}
