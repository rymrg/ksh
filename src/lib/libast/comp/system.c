/***********************************************************************
*                                                                      *
*               This software is part of the ast package               *
*          Copyright (c) 1985-2011 AT&T Intellectual Property          *
*          Copyright (c) 2020-2022 Contributors to ksh 93u+m           *
*                      and is licensed under the                       *
*                 Eclipse Public License, Version 2.0                  *
*                                                                      *
*                A copy of the License is available at                 *
*      https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html      *
*         (with md5 checksum 84283fa8859daf213bdda5a9f8d1be1d)         *
*                                                                      *
*                 Glenn Fowler <gsf@research.att.com>                  *
*                  David Korn <dgk@research.att.com>                   *
*                   Phong Vo <kpv@research.att.com>                    *
*                  Martijn Dekker <martijn@inlv.org>                   *
*            Johnothan King <johnothanking@protonmail.com>             *
*                                                                      *
***********************************************************************/
/*
 * AST library system(3)
 */

#define system		______system

#define _STDLIB_H_	1	/* UWIN workaround */

#include <ast.h>
#include <proc.h>

#undef	system

#undef	_def_map_ast
#include <ast_map.h>

extern int
system(const char* cmd)
{
	char*	sh[4];

	if (!cmd)
		return !eaccess(pathshell(), X_OK);
	sh[0] = "sh";
	sh[1] = "-c";
	sh[2] = (char*)cmd;
	sh[3] = 0;
	return procrun(NiL, sh, 0);
}
