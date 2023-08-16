// SPDX-FileCopyrightText: 2023 - 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include "nd-meta-provider.h"
#include "nd-pulseaudio.h"
#include "nd-screencast-portal.h"
#include "nd-sink.h"

#include <glib-object.h>


G_BEGIN_DECLS

#define ND_TYPE_DBUS_SINK (nd_dbus_sink_get_type ())

G_DECLARE_FINAL_TYPE (NdDbusSink, nd_dbus_sink, ND, DBUS_SINK, GObject)

NdDbusSink *nd_dbus_sink_new (NdMetaProvider *meta_provider,
                              gboolean use_x11,
                              NdScreencastPortal *portal,
                              NdSink *sink,
                              GDBusConnection *bus,
                              NdPulseaudio *pulse);
void nd_sink_dbus_export (NdDbusSink *self);
void nd_sink_dbus_stop_export (NdDbusSink *self);
gboolean nd_dbus_sink_equal_sink (NdDbusSink *self,
                                  NdSink *sink);
gchar *nd_sink_dbus_get_hw_address (NdDbusSink *self);
gchar *nd_sink_dbus_get_name (NdDbusSink *self);

G_END_DECLS
