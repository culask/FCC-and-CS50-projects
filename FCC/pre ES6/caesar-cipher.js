function rot13(str) {
    var cipher = [];
    for (var i = 0; i < str.length; i++){
        var ithCharCode = str.charCodeAt(i);
        var aCode = "A".charCodeAt(0);
        if (ithCharCode >= aCode && ithCharCode <= "Z".charCodeAt(0)){
            var rotatedCharCode = ((ithCharCode - aCode + 13) % 26) + aCode;
            cipher.push(String.fromCharCode(rotatedCharCode));
        } else {
            cipher.push(str[i]);
        }
    }
    return cipher.join("");
}
  