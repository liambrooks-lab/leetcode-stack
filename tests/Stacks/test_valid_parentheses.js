const fs = require('fs');
const path = require('path');

const code = fs.readFileSync(path.join(__dirname, '../../Stacks/valid_parentheses.js'), 'utf8');
eval(code);

function runTests() {
    if (isValid("()") !== true) throw new Error("Failed test 1");
    if (isValid("()[]{}") !== true) throw new Error("Failed test 2");
    if (isValid("(]") !== false) throw new Error("Failed test 3");
    console.log("test_valid_parentheses.js passed");
}

runTests();
