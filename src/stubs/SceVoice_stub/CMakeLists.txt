# Copyright (C) 2015 PSP2SDK Project
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(NIDS
    0x02f58d6f 0x09e4d18c 0x0a22ec0e 0x0b9e4ae2
    0x1f93fc0c 0x23c6b16b 0x2de35411 0x39aa3884
    0x5933ccfb 0x5e1ce910 0x5f0260f4 0x698bdaae
    0x6e46950e 0x73f72940 0x805cc20f 0x874054ce
    0x875cc80d 0x9b0d3490 0xac98853e 0xae46564d
    0xb2ed725b 0xc3868df6 0xc913f7e9 0xce855c50
    0xd02c00b4 0xd93769e6 0xdb90eac4 0xfa4e57b1
)

set(SRCS
    SceVoice_stub.S
)

add_psp2_stub(SceVoice ${SRCS} ${NIDS})
