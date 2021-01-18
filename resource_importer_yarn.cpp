/*************************************************************************/
/*  resource_importer_yarn.cpp                                           */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "resource_importer_yarn.h"
#include "core/io/file_access_pack.h"

String ResourceImporterYARN::get_preset_name(int p_idx) const {
	return String();
}

void ResourceImporterYARN::get_import_options(List<ImportOption> *r_options, int p_preset) const {
}

bool ResourceImporterYARN::get_option_visibility(const String &p_option, const Map<StringName, Variant> &p_options) const {
	return true;
}

String ResourceImporterYARN::get_importer_name() const {
	return "YARN";
}

String ResourceImporterYARN::get_visible_name() const {
	return "YARN";
}

void ResourceImporterYARN::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("yarn");
}

String ResourceImporterYARN::get_save_extension() const {
	return "res";
}

String ResourceImporterYARN::get_resource_type() const {
	return "YARNData";
}

int ResourceImporterYARN::get_preset_count() const {
	return 0;
}


Error ResourceImporterYARN::import(const String &p_source_file, const String &p_save_path, const Map<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata) {

	FileAccess *file = FileAccess::create(FileAccess::ACCESS_RESOURCES);
	Error err;
	String yarn_string = file->get_file_as_string(p_source_file, &err);
	ERR_FAIL_COND_V_MSG(err != OK, FAILED, "Can not open yarn file.");
	Ref<YARNData> yarn_data;
	yarn_data.instance();
	//String error_string;
	//int error_line;
	//Variant data;
	//err = JSON::parse(yarn_string, data, error_string, error_line);
	//yarn_data->set_data(data);
    yarn_data->set_yarn(yarn_string);
	return ResourceSaver::save(p_save_path + ".res", yarn_data);
}
