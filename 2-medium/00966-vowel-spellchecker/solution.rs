use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn spellchecker(wordlist: Vec<String>, mut queries: Vec<String>) -> Vec<String> {

        let mut exact_set: HashSet<String> = HashSet::new();
        let mut lower_map: HashMap<String, &str> = HashMap::new();
        let mut lower_vowel_map: HashMap<String, &str> = HashMap::new();

        let is_vowel = |c: char| matches!(c, 'a' | 'e' | 'i' | 'o' | 'u');
        let mask_vowels = |s: &str| s.chars().map(|ch| if is_vowel(ch) { '*' } else { ch }).collect::<String>();

        for i in 0..wordlist.len() {

            let word_lower = wordlist[i].to_lowercase();
            let word_lower_maskvowel = mask_vowels(&word_lower);

            lower_map.entry(word_lower).or_insert(&wordlist[i]);
            lower_vowel_map.entry(word_lower_maskvowel).or_insert(&wordlist[i]);
            exact_set.insert(wordlist[i].clone());
        }

        for i in 0..queries.len() {

            if !exact_set.contains(&queries[i]) {

                let query_lower = queries[i].to_lowercase();

                if let Some(word) = lower_map.get(&query_lower) {                    
                    queries[i] = word.to_string();
                } else if let Some(word) = lower_vowel_map.get(&mask_vowels(&query_lower)) {
                    queries[i] = word.to_string();
                } else {
                    queries[i].clear();
                }

            }
        }
        queries
    }
}
