#include <bits/stdc++.h>
using namespace std;

// line split
vector<string> split(string line) {
	vector<string> res;
	string prev = "";
	for (char i : line) {
		if (i == ' ') {
			if (prev != "") {
				res.push_back(prev);
				prev = "";
			}
		}
		else	prev += i;
	}
	if (prev != "")	res.push_back(prev);
	return res;
}

// word checking
bool is_word(string str) {
	for (char i : str) {
		if ('a' <= i && i <= 'z')	return true;
		if ('A' <= i && i <= 'Z')	return true;
	}
	return false;
}

// the holy grail checking
string THE_HOLY_GRAIL = "THEHOLYGRAIL";
string the_holy_grail = "theholygrail";
bool is_theholygrail(string line) {
	int pos = 0;
	for (char i : line) {
		if (pos == 12)	return true;
		if (THE_HOLY_GRAIL[pos] == i || the_holy_grail[pos] == i)	pos++;
	}
	return pos == 12;
}

// define counter

int taunt_counter = 0;
int sentence_counter = 0;
int noun_phrase_counter = 0;
int modified_noun_counter = 0;
int modifier_counter = 0;
int present_rel_counter = 0;
int past_rel_counter = 0;
int present_person_counter = 0;
int past_person_counter = 0;
int noun_counter = 0;
int present_verb_counter = 0;
int past_verb_counter = 0;
int article_counter = 0;
int adjective_counter = 0;
int adverb_counter = 0;

// define function

void taunt();
void sentence();
void noun_phrase();
void modified_noun();
void modifier();
void present_rel();
void past_rel();
void present_person();
void past_person();
void noun();
void present_verb();
void past_verb();
void article();
void adjective();
void adverb();

// Big letter checking
bool upper = 0;

void print(string str) {
	if (upper)	cout << (char)(str[0] - 32), upper = 0;
	else	cout << str[0];
	for (int i = 1; i < str.size(); i++)	cout << str[i];
}

void taunt() {
	upper = 1;
	switch (taunt_counter) {
	case 0:
		sentence();
		break;
	case 1:
		noun();
		print("! ");
		upper = 1;
		sentence();
		break;
	case 2:
		sentence();
		break;
	}
	taunt_counter = (taunt_counter + 1) % 3;
}

void sentence() {
	switch (sentence_counter) {
	case 0:
		past_rel();
		cout << ' ';
		noun_phrase();
		break;
	case 1:
		present_rel();
		cout << ' ';
		noun_phrase();
		break;
	case 2:
		past_rel();
		cout << ' ';
		article();
		cout << ' ';
		noun();
		break;
	}
	sentence_counter = (sentence_counter + 1) % 3;
}

void noun_phrase() {
	article();
	cout << ' ';
	modified_noun();
}

void modified_noun() {
	switch (modified_noun_counter) {
	case 0:
		noun();
		break;
	case 1:
		modifier();
		cout << ' ';
		noun();
		break;
	}
	modified_noun_counter = (modified_noun_counter + 1) % 2;
}

void modifier() {
	switch (modifier_counter) {
	case 0:
		adjective();
		break;
	case 1:
		adverb();
		cout << ' ';
		adjective();
		break;
	}
	modifier_counter = (modifier_counter + 1) % 2;
}

void present_rel() {
	print("your ");
	present_person();
	cout << ' ';
	present_verb();
}

void past_rel() {
	print("your ");
	past_person();
	cout << ' ';
	past_verb();
}

void present_person() {
	switch (present_person_counter) {
	case 0:
		print("steed");
		break;
	case 1:
		print("king");
		break;
	case 2:
		print("first-born");
		break;
	}
	present_person_counter = (present_person_counter + 1) % 3;
}

void past_person() {
	switch (past_person_counter) {
	case 0:
		print("mother");
		break;
	case 1:
		print("father");
		break;
	case 2:
		print("grandmother");
		break;
	case 3:
		print("grandfather");
		break;
	case 4:
		print("godfather");
		break;
	}
	past_person_counter = (past_person_counter + 1) % 5;
}

void noun() {
	switch (noun_counter) {
	case 0:
		print("hamster");
		break;
	case 1:
		print("coconut");
		break;
	case 2:
		print("duck");
		break;
	case 3:
		print("herring");
		break;
	case 4:
		print("newt");
		break;
	case 5:
		print("peril");
		break;
	case 6:
		print("chicken");
		break;
	case 7:
		print("vole");
		break;
	case 8:
		print("parrot");
		break;
	case 9:
		print("mouse");
		break;
	case 10:
		print("twit");
		break;
	}
	noun_counter = (noun_counter + 1) % 11;
}

void present_verb() {
	switch (present_verb_counter) {
	case 0:
		cout << "is";
		break;
	case 1:
		cout << "masquerades as";
		break;
	}
	present_verb_counter = (present_verb_counter + 1) % 2;
}

void past_verb() {
	switch (past_verb_counter) {
	case 0:
		cout << "was";
		break;
	case 1:
		cout << "personified";
		break;
	}
	past_verb_counter = (past_verb_counter + 1) % 2;
}

void article() {
	cout << "a";
}

void adjective() {
	switch (adjective_counter) {
	case 0:
		cout << "silly";
		break;
	case 1:
		cout << "wicked";
		break;
	case 2:
		cout << "sordid";
		break;
	case 3:
		cout << "naughty";
		break;
	case 4:
		cout << "repulsive";
		break;
	case 5:
		cout << "malodorous";
		break;
	case 6:
		cout << "ill-tempered";
		break;
	}
	adjective_counter = (adjective_counter + 1) % 7;
}

void adverb() {
	switch (adverb_counter) {
	case 0:
		cout << "conspicuously";
		break;
	case 1:
		cout << "categorically";
		break;
	case 2:
		cout << "positively";
		break;
	case 3:
		cout << "cruelly";
		break;
	case 4:
		cout << "incontrovertibly";
		break;
	}
	adverb_counter = (adverb_counter + 1) % 5;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string line;
	while (getline(cin, line)) {
		auto words = split(line);
		int word_count = 0;
		cout << "Knight: ";
		for (string word : words) {
			word_count += is_word(word);
			cout << word;
			cout << ' ';
		}
		cout << '\n';

		int taunt_count = (word_count - 1) / 3 + 1;

		if (is_theholygrail(line)) {
			taunt_count--;
			cout << "Taunter: (A childish hand gesture).\n";
		}

		while (taunt_count-- > 0) {
			cout << "Taunter: ";
			if (taunt_counter == 1)	taunt_count--;
			upper = 1;
			taunt();
			cout << ".\n";
		}
		cout << '\n';

	}

}