get_filename_component(shared_dir ${CMAKE_CURRENT_LIST_FILE} PATH)

include_directories(${shared_dir}/util)

set (SHARED_SRCS
)

set (SHARED_HEADERS
	${shared_dir}/util/field.h
)
