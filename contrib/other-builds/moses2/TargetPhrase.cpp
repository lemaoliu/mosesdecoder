/*
 * TargetPhrase.cpp
 *
 *  Created on: 23 Oct 2015
 *      Author: hieu
 */

#include <stdlib.h>
#include "TargetPhrase.h"
#include "Scores.h"
#include "Manager.h"
#include "StaticData.h"
#include "util/pool.hh"

using namespace std;

TargetPhrase *TargetPhrase::CreateFromString(util::Pool &pool, StaticData &staticData, const std::string &str)
{
	vector<string> toks = Moses::Tokenize(str);
	size_t size = toks.size();
	TargetPhrase *ret = new (pool.Allocate<TargetPhrase>()) TargetPhrase(pool, staticData, size);
	ret->Phrase::CreateFromString(toks);

	return ret;
}

TargetPhrase::TargetPhrase(util::Pool &pool, StaticData &staticData, size_t size)
:Phrase(pool, size)
{
	m_scores = new (pool.Allocate<Scores>()) Scores(pool, staticData.GetNumScores());
}

TargetPhrase::~TargetPhrase() {
	// TODO Auto-generated destructor stub
}
