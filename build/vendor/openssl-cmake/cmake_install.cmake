# Install script for directory: C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/SocketLib")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/ssl" TYPE FILE FILES
    "C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake/apps/openssl.cnf"
    "C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake/apps/ct_log_list.cnf"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  FILE(MAKE_DIRECTORY $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/ssl/certs)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  FILE(MAKE_DIRECTORY $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/ssl/misc)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  FILE(MAKE_DIRECTORY $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/ssl/private)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/c_rehash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openssl" TYPE FILE FILES
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/__DECC_INCLUDE_EPILOGUE.H"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/__DECC_INCLUDE_PROLOGUE.H"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/aes.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/asn1.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/asn1_mac.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/asn1err.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/asn1t.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/async.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/asyncerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/bio.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/bioerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/blowfish.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/bn.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/bnerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/buffer.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/buffererr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/camellia.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/cast.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/cmac.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/cms.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/cmserr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/comp.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/comperr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/conf.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/conf_api.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/conferr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/crypto.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/cryptoerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ct.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/cterr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/des.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/dh.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/dherr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/dsa.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/dsaerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/dtls1.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/e_os2.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ebcdic.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ec.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ecdh.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ecdsa.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ecerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/engine.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/engineerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/err.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/evp.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/evperr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/hmac.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/idea.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/kdf.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/kdferr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/lhash.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/md2.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/md4.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/md5.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/mdc2.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/modes.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/obj_mac.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/objects.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/objectserr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ocsp.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ocsperr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/opensslconf.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/opensslv.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ossl_typ.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/pem.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/pem2.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/pemerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/pkcs12.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/pkcs12err.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/pkcs7.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/pkcs7err.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/rand.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/rand_drbg.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/randerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/rc2.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/rc4.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/rc5.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ripemd.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/rsa.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/rsaerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/safestack.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/seed.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/sha.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/srp.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/srtp.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ssl.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ssl2.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ssl3.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/sslerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/stack.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/store.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/storeerr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/symhacks.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/tls1.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ts.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/tserr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/txt_db.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/ui.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/uierr.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/whrlpool.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/x509.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/x509_vfy.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/x509err.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/x509v3.h"
    "C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/include/openssl/x509v3err.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openssl" TYPE FILE FILES
    "C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake/FAQ"
    "C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake/LICENSE"
    "C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake/README"
    "C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake/README.ENGINE"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share" TYPE DIRECTORY FILES "C:/Users/Retr0/Desktop/SocketLib/vendor/openssl-cmake/doc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/crypto/cmake_install.cmake")
  include("C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/ssl/cmake_install.cmake")
  include("C:/Users/Retr0/Desktop/SocketLib/build/vendor/openssl-cmake/apps/cmake_install.cmake")

endif()

