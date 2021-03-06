/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MODPERL_PERL_UNEMBED_H
#define MODPERL_PERL_UNEMBED_H

#ifdef PERL_CORE
#   ifndef croak
#      define croak Perl_croak_nocontext
#   endif
#endif

/* avoiding namespace collisions */

/* from XSUB.h */
/* mod_perl.c calls exit() in a few places */
#undef exit
/* modperl_tipool.c references abort() */
#undef abort
/* these three clash with apr bucket structure member names */
#undef link
#undef read
#undef free
/* modperl_perl.c */
#ifdef WIN32
#   undef getpid
#   undef getenv
#endif

#undef list

#endif /* MODPERL_PERL_UNEMBED_H */
