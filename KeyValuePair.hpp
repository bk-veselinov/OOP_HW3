#pragma once
#define tp template<typename K, typename V> 

tp
class KeyValuePair {
	K key;
	V val;
public:
	const K& getKey()const;
	const V& getValue()const;

	 void setKey(const K& newKey);
	 void setValue(const V& newVal);

	KeyValuePair(const K& key,const V& value);
	KeyValuePair() = default;

};


tp
const K& KeyValuePair<K, V>::getKey() const{
	return key;
}

tp
const V& KeyValuePair<K, V>::getValue() const {
	return val;
}

tp
void KeyValuePair<K, V>::setKey(const K& newKey) {
	key = newKey;
}

tp
void KeyValuePair<K, V>::setValue(const V& newVal) {
	val = newVal;
}

tp
KeyValuePair<K, V>::KeyValuePair(const K& key, const V& value) {
	setKey(key);
	setValue(value);
}

