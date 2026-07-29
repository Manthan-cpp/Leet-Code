class Solution {
    vector<string> belowTen = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine"
    };

    vector<string> belowTwenty = {
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> belowHundred = {
        "", "Ten", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        if (num < 10)
            return belowTen[num];

        if (num < 20)
            return belowTwenty[num - 10];

        if (num < 100)
            return belowHundred[num / 10] +
                   (num % 10 ? " " + belowTen[num % 10] : "");

        if (num < 1000)
            return numberToWords(num / 100) + " Hundred" +
                   (num % 100 ? " " + numberToWords(num % 100) : "");

        if (num < 1000000)
            return numberToWords(num / 1000) + " Thousand" +
                   (num % 1000 ? " " + numberToWords(num % 1000) : "");

        if (num < 1000000000)
            return numberToWords(num / 1000000) + " Million" +
                   (num % 1000000 ? " " + numberToWords(num % 1000000) : "");

        return numberToWords(num / 1000000000) + " Billion" +
               (num % 1000000000 ? " " + numberToWords(num % 1000000000) : "");
    }
};