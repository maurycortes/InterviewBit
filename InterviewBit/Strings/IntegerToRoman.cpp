string Solution::intToRoman(int A) {
    struct romandata_t { int A; char const* numeral; };
    static romandata_t const romandata[] =
     { 1000, "M",
        900, "CM",
        500, "D",
        400, "CD",
        100, "C",
         90, "XC",
         50, "L",
         40, "XL",
         10, "X",
          9, "IX",
          5, "V",
          4, "IV",
          1, "I",
          0, NULL }; // end marker
 
    string result;
    for (romandata_t const* current = romandata; current->A > 0; ++current)
    {
        while (A >= current->A)
        {
            result += current->numeral;
            A  -= current->A;
        }
    }
    return result;
}
