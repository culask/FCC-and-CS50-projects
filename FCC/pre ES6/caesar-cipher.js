function rot13(str) {
    var cipher = [];
    for (var i = 0; i < str.length; i++){
        //get char code of ith char
        var ithCharCode = str.charCodeAt(i);
        var aCode = "A".charCodeAt(0);
        //check if char is alpha
        if (ithCharCode >= aCode && ithCharCode <= "Z".charCodeAt(0)){
            //rotate char and push to cipher
            var rotatedCharCode = ((ithCharCode - aCode + 13) % 26) + aCode;
            cipher.push(String.fromCharCode(rotatedCharCode));
        } else {
            //do not rotate and push
            cipher.push(str[i]);
        }
    }
    //build cipher as str and return
    return cipher.join("");
}
  