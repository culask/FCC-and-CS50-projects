function convertToRoman(num) {
    //add all the required roman characters and corresponding numbers
    var romanindex = [1000, 500, 100, 50, 10, 5, 1];
    var romanchar = ["M", "D", "C", "L", "X", "V", "I"];
    var romanstr = "";
    //iterate through all roman characters to populate roman string
    for (var i = 0; i < romanindex.length; i++){
        //integer division of the number to see how many times the character will be repeated
        var repeat = Math.floor(num / romanindex[i]);
        //repeats over 3 has special cases to handle
        if (repeat < 4){
            romanstr += romanchar[i].repeat(repeat);
        } else {
            //handle case of digit 9
            if (romanstr[romanstr.length - 1] === romanchar[i - 1]){
                romanstr = romanstr.substring(0, romanstr.length - 1);
                romanstr += romanchar[i] + romanchar[i - 2];
            //handle case of digit 4
            } else {
                romanstr += romanchar[i] + romanchar[i - 1];
            }
        }
        //reduce the number to look at next digit
        num = num % romanindex[i];
    }
    return romanstr;
}