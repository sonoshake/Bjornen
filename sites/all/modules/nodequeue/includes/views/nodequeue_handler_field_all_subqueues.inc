<?php
//$Id: nodequeue_handler_field_all_subqueues.inc,v 1.1 2008/09/06 15:42:05 ezrag Exp $
/**
 * Field handler for all subqueues
 *
 * @ingroup views_field_handlers
 */
class nodequeue_handler_field_all_subqueues extends nodequeue_handler_field_all_queues {
  function pre_render($values) {
    $nids = array();
    foreach ($values as $result) {
      $nids[] = $result->{$this->field_alias};
    }

    if ($nids) {
      $queue = '';
      if (!empty($this->options['limit']) && !empty($this->options['qids'])) {
        $queue = " AND nn.qid IN (" . implode(', ', array_keys(array_filter($this->options['qids']))) . ")";
      }

      $result = db_query("SELECT nn.nid, nn.sqid, nn.qid, nq.subqueue_title, ns.title FROM {nodequeue_nodes} nn INNER JOIN {nodequeue_queue} nq ON nq.qid = nn.qid INNER JOIN {nodequeue_subqueue} ns on nn.sqid = ns.sqid WHERE nn.nid IN (" . implode(', ', $nids) . ")$queue ORDER BY ns.title, nq.subqueue_title");

      while ($queue = db_fetch_object($result)) {
        $title = empty($queue->subqueue_title) ? $queue->title : str_replace('%subqueue', $queue->title, $queue->subqueue_title);
        if (empty($this->options['link_to_queue'])) {
          $this->items[$queue->nid][$queue->sqid] = check_plain($title);
        }
        else {
          $this->items[$queue->nid][$queue->sqid] = l($title, "admin/content/nodequeue/$queue->qid/$queue->sqid");
        }
      }
    }
  }
}