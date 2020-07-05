// Copyright (c) 2012-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The Astracore developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

/**
 * Functionality for communicating with AstraGate.
 */
#ifndef BITCOIN_ASTRACONTROL_H
#define BITCOIN_ASTRACONTROL_H

#include <string>

#include <boost/function.hpp>
#include <boost/chrono/chrono.hpp>
#include <boost/thread.hpp>

extern const std::string DEFAULT_ASTRA_CONTROL;
static const bool DEFAULT_LISTEN_ONION = true;

void StartAstraControl(boost::thread_group& threadGroup);
void InterruptAstraControl();
void StopAstraControl();

#endif /* BITCOIN_ASTRACONTROL_H */


