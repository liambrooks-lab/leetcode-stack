var shortestBeautifulSubstring = function (s, k) {
  let minimumLengthFound = Infinity;
  let finalResultString = "";
  let leftPointer = 0;
  let currentOneCounter = 0;

  for (let rightPointer = 0; rightPointer < s.length; rightPointer++) {
    if (s[rightPointer] === "1") {
      currentOneCounter++;
    }

    while (currentOneCounter === k) {
      const currentWindowLen = rightPointer - leftPointer + 1;
      const currentSubstringValue = s.substring(leftPointer, rightPointer + 1);

      if (currentWindowLen < minimumLengthFound) {
        minimumLengthFound = currentWindowLen;
        finalResultString = currentSubstringValue;
      } else if (currentWindowLen === minimumLengthFound) {
        if (currentSubstringValue < finalResultString) {
          finalResultString = currentSubstringValue;
        }
      }

      if (s[leftPointer] === "1") {
        currentOneCounter--;
      }
      leftPointer++;
    }
  }

  return finalResultString;
};