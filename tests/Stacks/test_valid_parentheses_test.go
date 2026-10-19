package stacks_test

import (
	"testing"

	"leetcode-stack/Stacks"
)

func TestValidParentheses(t *testing.T) {
	if !stacks.IsValid("()") {
		t.Fatalf("Failed test 1: expected true for \"()\"")
	}
	if !stacks.IsValid("()[]{}") {
		t.Fatalf("Failed test 2: expected true for \"()[]{}\"")
	}
	if stacks.IsValid("(]") {
		t.Fatalf("Failed test 3: expected false for \"(]\"")
	}
}
