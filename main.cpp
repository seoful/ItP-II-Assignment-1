#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief Splits a text given in the string into the sentences ending by a dot.
 * @param text a text to split into sentences
 * @return a vector of sentences ending with dots.
 */
vector<string> break_into_sentences(const string &text) {
    vector<string> sentences;
    int sentence_beginning = 0;
    while (sentence_beginning < text.length() - 1) {
        int sentence_end = text.find_first_of(".!?", sentence_beginning);
        string sentence = text.substr(sentence_beginning, sentence_end - sentence_beginning + 1);
        sentences.push_back(sentence);
        sentence_beginning = text.find_first_not_of(" .?!", sentence_end + 1);
    }
    return sentences;
}

/**
 * @brief Converts the string to uppercase
 * @param str a string to convert
 */
void string_to_upper(string &str) {
    for (auto &c : str) c = (char) toupper(c);
}

/**
 * @brief Highlights all occurrences of a word in the given sentence
 * @param sentence a sentence to search through
 * @param word_to_highlight a word to highlight
 * @return true if the word was found and false, otherwise
 */
bool highlight_word_in_sentence(string &sentence, string word_to_highlight) {
    bool word_found = false;
    string_to_upper(word_to_highlight);
    int word_beginning = 0;
    while (word_beginning < sentence.length() - 2) { //-2 as we have a dot in the end of the sentence
        int word_end = sentence.find_first_of(" ,:;()-_+='\"`~[]{}^&%$#@|\\", word_beginning); //Searching for the end of the word
        int word_len = word_end - word_beginning;
        string current_word = sentence.substr(word_beginning, word_len); //Getting the word
        string_to_upper(current_word);
        if (current_word == word_to_highlight) { //Check the word for equality
            word_found = true;
            sentence.replace(word_beginning, word_len, current_word); //Highlighting the word in a given sentence
        }
        word_beginning = sentence.find_first_not_of(" ,:;()-_+='\"`~[]{}^&%$#@|\\", word_end); //Proceeding to the next word.
    }
    return word_found;
}

/**
 * @brief Finds all sentences with the occurrence of the specified word, highlighting the word
 * @param sentences - a vector of sentences to search through
 * @param word - a word to find and highlight
 * @return - a vector of sentences with the word highlighted
 */
vector<string> find_sentences_by_word(vector<string> sentences, const string &word) {
    vector<string> chosen_sentences; //An array to keep sentences with the specified word
    for (string &sentence: sentences) {
        if (highlight_word_in_sentence(sentence, word))
            chosen_sentences.push_back(sentence);
    }
    return chosen_sentences;
}

int main() {
    ifstream in(R"(..\in.txt)");
    ofstream out(R"(..\out.txt)");
    string inputText;
    getline(in, inputText); //Reading text from file
    auto sentences = break_into_sentences(inputText);

    int n;
    in >> n; //Read number of words to search
    for (int i = 0; i < n; i++) {
        string query;
        in >> query; //Read the word to search
        vector<string> chosen_sentences = find_sentences_by_word(sentences, query);
        out << chosen_sentences.size() << endl;
        for (const auto &sentence : chosen_sentences)
            out << sentence << endl;
    }
}
