function palindrome(str) {
    //remove non-alpha chars and make it case insensitive
    str = str.replace(/[^0-9a-z]/gi, '').toLowerCase();
    //compare with reversed str
    return str === str.split("").reverse().join("");
}
  