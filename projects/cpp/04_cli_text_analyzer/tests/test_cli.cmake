set(first "${FIXTURES}/cli_first.txt")
set(second "${FIXTURES}/cli_second.txt")
set(empty "${FIXTURES}/cli_empty.txt")
set(missing "${FIXTURES}/this_file_does_not_exist.txt")
set(stop "${FIXTURES}/cli_stop_words.txt")

execute_process(COMMAND "${PROGRAM}" 3 "${first}" "${missing}" "${second}"
    RESULT_VARIABLE status OUTPUT_VARIABLE output ERROR_VARIABLE errors)
if(NOT status EQUAL 0 OR NOT output STREQUAL "Word: cat\nCounts: 2\nWord: bird\nCounts: 1\nWord: dog\nCounts: 1\n" OR NOT errors MATCHES "Cannot read file:")
    message(FATAL_ERROR "Partial failure or merged output incorrect: ${status} ${output} ${errors}")
endif()

execute_process(COMMAND "${PROGRAM}" 3 "${missing}"
    RESULT_VARIABLE status OUTPUT_VARIABLE output ERROR_VARIABLE errors)
if(status EQUAL 0 OR NOT errors MATCHES "No files could be read")
    message(FATAL_ERROR "All-failed case incorrect")
endif()

execute_process(COMMAND "${PROGRAM}" 3 "${empty}"
    RESULT_VARIABLE status OUTPUT_VARIABLE output ERROR_VARIABLE errors)
if(NOT status EQUAL 0 OR NOT output STREQUAL "" OR NOT errors STREQUAL "")
    message(FATAL_ERROR "Empty file case incorrect")
endif()

execute_process(COMMAND "${PROGRAM}" 0 "${first}" "${second}"
    RESULT_VARIABLE status OUTPUT_VARIABLE output)
if(NOT status EQUAL 0 OR NOT output STREQUAL "")
    message(FATAL_ERROR "K=0 case incorrect")
endif()

execute_process(COMMAND "${PROGRAM}" 3 --stop-words "${stop}" "${first}" "${second}"
    RESULT_VARIABLE status OUTPUT_VARIABLE output ERROR_VARIABLE errors)
if(NOT status EQUAL 0 OR NOT output STREQUAL "Word: dog\nCounts: 1\n" OR NOT errors STREQUAL "")
    message(FATAL_ERROR "Stop-word filtering incorrect: ${status} ${output} ${errors}")
endif()

execute_process(COMMAND "${PROGRAM}" 3 --stop-words "${missing}" "${first}"
    RESULT_VARIABLE status ERROR_VARIABLE errors)
if(status EQUAL 0 OR NOT errors MATCHES "Cannot read stop-words file:")
    message(FATAL_ERROR "Missing stop-word file case incorrect")
endif()

foreach(args "--stop-words" "--stop-words;${stop}")
    execute_process(COMMAND "${PROGRAM}" 3 ${args}
        RESULT_VARIABLE status ERROR_VARIABLE errors)
    if(status EQUAL 0 OR NOT errors MATCHES "Expected a stop-words file")
        message(FATAL_ERROR "Missing option argument or input file case incorrect")
    endif()
endforeach()
