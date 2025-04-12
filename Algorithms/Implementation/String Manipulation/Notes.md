Practical Examples
Reverse a String

function reverseString(str) {
  return str.split("").reverse().join("");
}
console.log(reverseString("JavaScript")); // "tpircSavaJ"

Check for a Palindrome

function isPalindrome(str) {
  // Remove non-alphanumeric characters and convert to lowercase
  let cleaned = str.replace(/[\W_]/g, "").toLowerCase();
  return cleaned === reverseString(cleaned);
}
console.log(isPalindrome("A man, a plan, a canal, Panama")); // true

Capitalize Each Word

function capitalizeWords(str) {
  return str.split(" ").map(word => 
    word.charAt(0).toUpperCase() + word.slice(1).toLowerCase()
  ).join(" ");
}
console.log(capitalizeWords("hello world")); // "Hello World"