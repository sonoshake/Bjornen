<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<div class="medverkande">
	<div class="bild">
		<?php print $fields['field_artist_image_fid']->content ?>
	</div>

	<div class="info">
		<p>
			<b><?php print $fields['title']->content ?></b>
			<br />
			<em><?php print $fields['field_artist_info_value']->content ?></em>
		</p>
		<p>
			<?php print $fields['teaser']->content ?>
			<br />
			<?php print $fields['view_node']->content ?>
		</p>
	</div>
</div>